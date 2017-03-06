using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;
using Foundation.Databinding;

namespace NFF
{
	#region Recyle 改造增加部分 - 列表信息定义以及计算逻辑

	/// <summary>
	/// 重利用单元格信息.
	/// </summary>
	[System.Serializable]
	public class RecyleCell {
		public int Index {
			get;
			set;
		}
		public int RecyleIndex {
			get;
			set;
		}
		public GameObject Cell {
			get;
			set;
		}
	}

	/// <summary>
	/// 重利用单元格位置信息.
	/// </summary>
	[System.Serializable]
	public class RecyleCellPosInfo {
		public int Index {
			get;
			set;
		}
		public Vector3 Position {
			get;
			set;
		}
	}

	[System.Serializable]
	public class RecyleBindingData {
		public int Index {
			get;
			set;
		}

		public BindingContext Binder {
			get;
			set;
		}
		public object Data {
			get;
			set;
		}
	}

	/// <summary>
	/// 视图信息.
	/// </summary>
	[System.Serializable]
	public class RecyleViewInfo {

		/// <summary>
		/// 排序（ true : 升序; false : 降序;）.
		/// </summary>
		/// <value><c>true</c> 升序; 降序, <c>false</c>.</value>
		private bool isOrderByAsc {
			get;
			set;
		}

		/// <summary>
		/// 滚动类型.
		/// </summary>
		/// <value>滚动类型.</value>
		private TScrollType ScrollType {
			get;
			set;
		}

		/// <summary>
		/// 横向滑动标识.
		/// </summary>
		public bool IsHorizontal {
			get { return ((TScrollType.kHorizontal == this.ScrollType) || (TScrollType.kBoth == this.ScrollType)); }
		}
		/// <summary>
		/// 纵向滑动标识.
		/// </summary>
		public bool IsVertical {
			get { return ((TScrollType.kVeritcal == this.ScrollType) || (TScrollType.kBoth == this.ScrollType)); }
		}

		/// <summary>
		/// 双向滑动标识.
		/// </summary>
		/// <value><c>true</c> 双向滑动; 非双向滑动, <c>false</c>.</value>
		public bool IsBoth {
			get { return (TScrollType.kBoth == this.ScrollType);}
		}

		/// <summary>
		/// 重利用缓冲个数.
		/// </summary>
		public const int _recyleBuffCount = 1;

		/// <summary>
		/// 视图列数.
		/// </summary>
		/// <value>视图列数.</value>
		public int ViewColsNum {
			get;
			set;
		}

		/// <summary>
		/// 视图行数.
		/// </summary>
		/// <value>视图行数.</value>
		public int ViewRowsNum {
			get;
			set;
		}
			
		/// <summary>
		/// 重利用列数.
		/// </summary>
		/// <value>重利用列数.</value>
		public int RecyleColsNum {
			get { return this.IsHorizontal ? (this.ViewColsNum + _recyleBuffCount) : this.ViewColsNum; }
		}
		/// <summary>
		/// 重利用行数.
		/// </summary>
		/// <value>重利用行数.</value>
		public int RecyleRowsNum {
			get { return this.IsVertical ? (this.ViewRowsNum + _recyleBuffCount) : this.ViewRowsNum; }
		}

		/// <summary>
		/// 重利用单元格总数.
		/// </summary>
		/// <value>重利用单元格总数.</value>
		public int RecyleCellsCount {
			get { return (this.RecyleColsNum * this.RecyleRowsNum); }
		}

		/// <summary>
		/// 内容列数.
		/// </summary>
		/// <value>内容列数.</value>
		public int ContentColsCount {
			get;
			set;
		}

		/// <summary>
		/// 内容行数.
		/// </summary>
		/// <value>内容行数.</value>
		public int ContentRowsCount {
			get;
			set;
		}

		/// <summary>
		/// 单元格尺寸.(不包含，单元格上下左右边距).
		/// </summary>
		private Vector2 _cellSize = Vector2.zero;
		/// <summary>
		/// 单元格锚点.
		/// </summary>
		private Vector2 _cellAnchor = Vector2.zero;
		/// <summary>
		/// 单元格轴心点.
		/// </summary>
		private Vector2 _cellPivot = Vector2.zero;

		/// <summary>
		/// 单元格宽度.(不包含，单元格左右边距).
		/// </summary>
		/// <value>单元格宽度.(不包含，单元格左右边距).</value>
		public float CellWidth {
			get { return this._cellSize.x; }
		}

		/// <summary>
		/// 单元格高度.(不包含，单元格上下边距).
		/// </summary>
		/// <value>单元格高度..(不包含，单元格上下边距).</value>
		public float CellHeight {
			get { return this._cellSize.y; }
		}

		/// <summary>
		/// 设定单元格尺寸.
		/// </summary>
		/// <param name="iSize">尺寸.</param>
		/// <param name="iPivot">Pivot.</param>
		public void SetCellSize(Vector2 iSize, Vector2 iPivot) {
			this._cellSize = iSize;
			this._cellPivot = iPivot;
		}

		/// <summary>
		/// 设定单元格尺寸.
		/// </summary>
		/// <param name="iWidth">宽度.</param>
		/// <param name="iHeight">高度.</param>
		public void SetCellSize(float iWidth, float iHeight) {
			this._cellSize.x = iWidth;
			this._cellSize.y = iHeight;
		}
			
		/// <summary>
		/// 视图尺寸.(包含，上下左右边距).
		/// </summary>
		/// <value>视图尺寸(包含，上下左右边距)..</value>
		public Vector2 ViewSize {
			get;
			set;
		}

		/// <summary>
		/// 视图宽度.(包含，左右边距).
		/// </summary>
		/// <value>视图宽度.(包含，左右边距).</value>
		public float ViewWidth {
			get { return this.ViewSize.x; }
		}

		/// <summary>
		/// 视图高度.(包含，上下边距).
		/// </summary>
		/// <value>视图高度.(包含，上下边距).</value>
		public float ViewHeight {
			get { return this.ViewSize.y; }
		}



		/// <summary>
		/// 内容尺寸.
		/// </summary>
		/// <value>内容尺寸.</value>
		public Vector2 ContentSize {
			get;
			set;
		}

		/// <summary>
		/// 内容起始偏移
		/// </summary>
		/// <value>内容起始偏移.</value>
		public Vector3 ContentStartOffset {
			get;
			set;
		}

		/// <summary>
		/// 内容宽度.
		/// </summary>
		/// <value>内容宽度.</value>
		public float ContentWidth {
			get { return this.ContentSize.x; }
		}

		/// <summary>
		/// 内容高度.
		/// </summary>
		/// <value>内容高度.</value>
		public float ContentHeight {
			get { return this.ContentSize.y; }
		}

		/// <summary>
		/// 视图边距.
		/// </summary>
		/// <value>view padding.</value>
		public RectOffset ViewPadding {
			get;
			set;
		}

		/// <summary>
		/// 单元格边距.
		/// </summary>
		/// <value>The cell padding.</value>
		public RectOffset CellPadding {
			get;
			set;
		}

		/// <summary>
		/// 单元格总数.
		/// </summary>
		/// <value>单元格总数.</value>
		public int CellsCount {
			get;
			set;
		}

		/// <summary>
		/// 内容行数.
		/// </summary>
		/// <value>内容行数.</value>
		public int ContentRowsNum {
			get { 
				if (this.IsBoth) {
					Debug.LogErrorFormat ("The scroll type of recyleview has not been supported yet!!!{0}", this.ScrollType);
					return -1;
				} else if (this.IsVertical) {
					int mod = this.CellsCount % this.ViewColsNum;
					int num = (this.CellsCount - mod) / this.ViewColsNum;
					num = (mod > 0) ? (num + 1) : num;
					return num; 
				} else if (this.IsHorizontal) {
					return this.ViewRowsNum;
				} else {
					return this.ViewRowsNum; 
				}
			}
		}

		/// <summary>
		/// 内容列数.
		/// </summary>
		/// <value>内容列数.</value>
		public int ContentColsNum {
			get { 
				if (this.IsBoth) {
					Debug.LogErrorFormat ("The scroll type of recyleview has not been supported yet!!!{0}", this.ScrollType);
					return -1;
				} else if (this.IsVertical) {
					return this.ViewColsNum; 
				} else if (this.IsHorizontal) {
					
					int mod = this.CellsCount % this.ViewRowsNum;
					int num = (this.CellsCount - mod) / this.ViewRowsNum;
					num = (mod > 0) ? (num + 1) : num;
					return num; 

				} else {
					return this.ViewColsNum; 
				}
			}
		}

		/// <summary>
		/// cell列表坐标一栏（localtion）.
		/// </summary>
		private List<RecyleCellPosInfo> _cellsPos = new List<RecyleCellPosInfo>();

		/// <summary>
		/// 创建重利用列表信息.
		/// </summary>
		/// <param name="iScrollType">滚动类型.</param>
		/// <param name="iIsOrderByAsc">排序（ true : 升序; false : 降序;）.</param>
		/// <param name="iColNum">列数.</param>
		/// <param name="iRowsNum">行数.</param>
		/// <param name="iViewSize">视图尺寸.</param>
		/// <param name="iViewPadding">视图范围边距.</param>
		public static RecyleViewInfo Create (
			TScrollType iScrollType,
			bool iIsOrderByAsc,
			int iColsNum,
			int iRowsNum,
			Vector2 iViewSize,
			RectOffset iViewPadding) {

			RecyleViewInfo ret = new RecyleViewInfo ();
			ret.initByViewInfo (
				iScrollType, iIsOrderByAsc,
				iColsNum, iRowsNum,
				iViewSize, iViewPadding);

			return ret;

		}

		protected RecyleViewInfo() {
		}

		/// <summary>
		/// 初始化.
		/// </summary>
		/// <param name="iScrollType">滚动类型.</param>
		/// <param name="iIsOrderByAsc">排序（ true : 升序; false : 降序;）.</param>
		/// <param name="iColNum">列数.</param>
		/// <param name="iRowsNum">行数.</param>
		/// <param name="iViewPadding">视图范围边距.</param>
		/// <param name="iDisplaySize">Content显示尺寸.</param>
		public void initByViewInfo (
			TScrollType iScrollType,
			bool iIsOrderByAsc,
			int iColsNum,
			int iRowsNum,
			Vector2 iViewSize,
			RectOffset iViewPadding) {

			// 设定视图信息
			this.SetViewInfo (iScrollType, iIsOrderByAsc, iViewSize, iViewPadding);

			// 横向滚动设定视图行数
			if (this.IsHorizontal) {
				this.ViewRowsNum = iRowsNum;
			}

			// 纵向滚动设定视图列数
			if (this.IsVertical) {
				this.ViewColsNum = iColsNum;
			}
		}

		/// <summary>
		/// Inits the by cell info.
		/// </summary>
		/// <param name="iCellSize">单元格尺寸.</param>
		/// <param name="iCellAnchor">单元格描点（(min + max) / 2）.</param>
		/// <param name="iCellPivot">单元格轴心点.</param>
		/// <param name="iCellPadding">单元格边距情报.</param>
		public void initByCellInfo(
			Vector2 iCellSize, 
			Vector2 iCellAnchor,
			Vector2 iCellPivot, 
			RectOffset iCellPadding) {

			// 设定单元格信息
			this.SetCellSizeInfo (iCellSize, iCellPadding, iCellAnchor, iCellPivot);

			// 自动计算各项信息
			this.AutoCalcInitInfo();

		}

		/// <summary>
		/// 设定视图信息.
		/// </summary>
		/// <param name="iScrollType">滚动类型.</param>
		/// <param name="iIsOrderByAsc">排序（ true : 升序; false : 降序;）.</param>
		/// <param name="iViewSize">视图尺寸.</param>
		/// <param name="iViewPadding">视图边距.</param>
		public void SetViewInfo(
			TScrollType iScrollType, bool iIsOrderByAsc,
			Vector2 iViewSize, RectOffset iViewPadding) {

			if (TScrollType.kBoth == iScrollType) {
				Debug.LogErrorFormat ("The scroll type of recyleview has not been supported yet!!!{0}", iScrollType);
				return;
			}

			this.ScrollType = iScrollType;
			this.isOrderByAsc = iIsOrderByAsc;
			this.ViewSize = iViewSize;
			this.ViewPadding = iViewPadding;
		}

		/// <summary>
		/// 设定单元格尺寸信息.
		/// </summary>
		/// <param name="iCellSize">单元格尺寸.</param>
		/// <param name="iCellPadding">单元格边距信息.</param>
		/// <param name="iCellAnchor">单元格锚点.</param>
		/// <param name="iCellPivot">单元格轴心点.</param>
		public void SetCellSizeInfo(Vector2 iCellSize,
			RectOffset iCellPadding, Vector2 iCellAnchor, Vector2 iCellPivot) {

			this.CellPadding = iCellPadding;
			this._cellAnchor = iCellAnchor;
			this._cellPivot = iCellPivot;

			this._cellSize = iCellSize;
			// 根据显示范围宽度，调整单元格宽度
			this._cellSize.x = (this.ViewWidth - this.ViewPadding.left - this.ViewPadding.right) / this.ViewColsNum;
			this._cellSize.x -= this.CellPadding.left;
			this._cellSize.x -= this.CellPadding.right;
		}

		/// <summary>
		/// 自动计算初始化信息.
		/// </summary>
		private void AutoCalcInitInfo() {

			// 横向滚动计算视图列数
			if (this.IsHorizontal == true) {
				float viewWidthTmp = this.ViewWidth - this.ViewPadding.left - this.ViewPadding.right;
				this.ViewColsNum = 
					(int)(viewWidthTmp / ((this.CellPadding.left + this.CellWidth + this.CellPadding.right) * this.ViewColsNum));
				
			}

			// 纵向滚动计算视图行数
			if (this.IsVertical == true) {
				float viewHeightTmp = this.ViewHeight - this.ViewPadding.top - this.ViewPadding.bottom;
				this.ViewRowsNum = 
					(int)(viewHeightTmp / (this.CellPadding.top + this.CellHeight + this.CellPadding.bottom));
			}
		}

		/// <summary>
		/// 重置Conteng Size.
		/// </summary>
		/// <returns>是否进行了重置.</returns>
		/// <param name="iCellCount">单元格总数.</param>
		public bool ResetContentSizeByCellsCount(int iCellsCount) {

			// 单元格总数没有变化
			if(iCellsCount == this.CellsCount) {
				return false;
			}
			this.CellsCount = iCellsCount;

			if (IsBoth) {
				Debug.LogErrorFormat ("The scroll type of recyleview has not been supported yet!!!{0}", this.ScrollType);
				return false;
			}

			float contentSizeW = 0.0f;
			float contentSizeH = 0.0f;
			int deltaIndex = 0;
			if (this.IsHorizontal) {
				contentSizeW += this.ViewPadding.left;
				contentSizeW += (this.CellPadding.left + this.CellWidth + this.CellPadding.right) * this.ContentColsNum;
				contentSizeW += this.ViewPadding.right;

				contentSizeH += this.ViewHeight;

			} else if (this.IsVertical) {
				contentSizeW += this.ViewWidth;

				contentSizeH += this.ViewPadding.top;
				contentSizeH += (this.CellPadding.top + this.CellHeight + this.CellPadding.bottom) * this.ContentRowsNum;
				contentSizeH += this.ViewPadding.bottom;
	
			}
			this.SetContentSize (contentSizeW, contentSizeH);

			// 计算起始偏移(升序，则重置)
			if (this.isOrderByAsc) {

				if ((IsHorizontal == true) &&
					(this.ContentWidth <= this.ViewWidth)) {
					this.ContentStartOffset = Vector3.zero;
				} else if ((IsVertical == true) &&
					(this.ContentHeight <= this.ViewHeight)) {
					this.ContentStartOffset = Vector3.zero;
				} else {
					this.ContentStartOffset = this.ContentSize - this.ViewSize;
				}

			} else {
				this.ContentStartOffset = Vector3.zero;
			}

			// 重新计算所有单元格坐标
			this.AutoPrevCalcLocalPosOfAllCells(iCellsCount);

			return true;
		}

		/// <summary>
		/// 设定视图尺寸.
		/// </summary>
		/// <param name="iWidth">视图宽度.</param>
		/// <param name="iHeight">视图高度.</param>
		public void SetViewSize(float iWidth, float iHeight) {
			this.ViewSize = new Vector2 (iWidth, iHeight);
		}

		/// <summary>
		/// 设定列表尺寸.
		/// </summary>
		/// <param name="iSize">尺寸.</param>
		public void SetContentSize(Vector2 iSize) {
			this.ContentSize = iSize;
		}

		/// <summary>
		/// 设定列表尺寸.
		/// </summary>
		/// <param name="iWidth">宽度.</param>
		/// <param name="iHeight">高度.</param>
		public void SetContentSize(float iWidth, float iHeight) {
			this.ContentSize = new Vector2(iWidth, iHeight);
		}

		/// <summary>
		/// 计算新新单元格的坐标.
		/// </summary>
		/// <returns>新单元格的坐标.</returns>
		/// <param name="iCellIndex">cell index.</param>
		private Vector3 CalcNewCellLocalPos(int iCellIndex) {

			int cellNo = iCellIndex + 1;
			int colNo = cellNo % this.ViewColsNum;
			int colIndex = ((colNo - 1) + this.ViewColsNum ) % this.ViewColsNum;

			// 单列宽度(包含单元格之间的边距)
			float colWidth = this.CellPadding.left + this.CellWidth + this.CellPadding.right;
			float cellPosX = colWidth * colIndex + this.CellPadding.left + this.CellWidth * this._cellPivot.x;;
			cellPosX += this.ViewPadding.left;

			Vector2 vecX = new Vector2(-(this.ContentWidth * this._cellAnchor.x), 0.0f);
			Vector2 vecCellX = new Vector2 (cellPosX, 0.0f);
			vecX += vecCellX;

			int rowIndex = ((cellNo - colNo) / this.ViewColsNum) - 1;
			if (colNo > 0) {
				rowIndex += 1;
			}
			// 单行高度
			float rowHeight = this.CellPadding.top + this.CellHeight + this.CellPadding.bottom;
			float cellPosY = rowHeight * rowIndex + this.CellPadding.top + this.CellHeight * (1.0f - this._cellPivot.y);
			cellPosY += this.ViewPadding.top;

			Vector2 vecY = new Vector2 (0.0f, this.ContentHeight * (1.0f - this._cellAnchor.y));
			
			Vector2 vecCellY = new Vector2 (0.0f, -cellPosY);
			vecY += vecCellY;

			Vector2 vecRet = vecX + vecY;

			return new Vector3(vecRet.x, vecRet.y, 0.0f);
		}

		/// <summary>
		/// 预先自动计算所有单元格坐标.
		/// </summary>
		/// <param name="iCellsCount">单元格数.</param>
		private void AutoPrevCalcLocalPosOfAllCells(int iCellsCount) {

			// 清空
			this._cellsPos.Clear ();

			// 计算各个单元格坐标
			for (int cellIdx = 0; cellIdx < this.CellsCount; ++cellIdx) {
				RecyleCellPosInfo cellInfo = new RecyleCellPosInfo ();
				cellInfo.Index = cellIdx;
				cellInfo.Position = this.CalcNewCellLocalPos (cellIdx);
				this._cellsPos.Add(cellInfo);
			}
		}

		/// <summary>
		/// 取得单元格坐标.
		/// </summary>
		/// <returns>单元格坐标.</returns>
		/// <param name="iCellIndex">单元格Index.</param>
		public bool GetCellPos(int iCellIndex, out Vector3 ioCellPos) {
			ioCellPos = Vector2.zero;
			if (this._cellsPos.Count > iCellIndex) {

				// 升序
				if(this.isOrderByAsc) {
					RecyleCellPosInfo[] cellsPos = this._cellsPos.OrderBy (o => o.Index).ToArray();
						ioCellPos = (cellsPos[iCellIndex]).Position;
				} else {
					RecyleCellPosInfo[] cellsPos = this._cellsPos.OrderByDescending (o => o.Index).ToArray();
					// 降序
					ioCellPos = (cellsPos[iCellIndex]).Position;
				}
				return true;
			}
			return false;
		}

		/// <summary>
		/// 清空函数.
		/// </summary>
		/// <param name="iAllClear">全清空标志位.</param>
		public void ClearInfo(bool iAllClear) {
			if (iAllClear == true) {

				this.ScrollType = TScrollType.kDefault;

				this.ViewColsNum = 0;
				this.ViewRowsNum = 0;
				this.ViewSize = Vector2.zero;
				this.ViewPadding = new RectOffset(0, 0, 0, 0);

				this.ContentColsCount = 0;
				this.ContentRowsCount = 0;
				this.ContentSize = Vector2.zero;

				this._cellSize = Vector2.zero;
				this._cellAnchor = Vector2.zero;
				this._cellPivot = Vector2.zero;
				this.CellPadding = new RectOffset(0, 0, 0, 0);
			} 
			this._cellsPos.Clear ();
			this.CellsCount = 0;
		}

	}
	#endregion


    /// <summary>
    ///     Presents an array, observable collection or other IEnumerable visually.
    /// </summary>
    /// <remarks>
    ///     The Prefab (child template) should have a binding context set to Mock binding
    /// </remarks>
	[AddComponentMenu("NFF/RecyleScrollView/RecyleListBinder")]
	public class RecyleListBinder : BindingBase
    {
        protected List<BindingContext> Children = new List<BindingContext>();
        protected IObservableCollection DataList;
		public Dictionary<int, RecyleBindingData> Datas = new Dictionary<int, RecyleBindingData>();
        public bool DelayLoad;
        protected int CellIndex;
        protected bool IsInit;
        protected bool IsLoaded;

        /// <summary>
        ///     Shown when loading
        /// </summary>
        public GameObject LoadingMask;

        /// <summary>
        ///     True if this is a static list.
        ///     The list will only update once.
        /// </summary>
        public bool OneTime;

        /// <summary>
        ///     Cell预制体
        /// </summary>
        /// <remarks>
		///     用来生成Cell的预制体
        /// </remarks>
        public GameObject CellPrefab;

        protected RectTransform _contentRectTrans;
        protected RectTransform _cellRectTrans;

		#region Recyle 改造增加部分 - 参数定义

		/// <summary>
		/// The view rect.
		/// </summary>
		[SerializeField] private ScrollRect _scrollRect = null;

		/// <summary>
		/// View 边距.
		/// </summary>
		[SerializeField] private RectOffset _viewPadding = null;

		/// <summary>
		/// 升序标志位（true : 升序; false : 降序;）.
		/// </summary>
		[SerializeField] private bool _isOrderByAsc = true;

		/// <summary>
		/// 自动修正偏移.
		/// </summary>
		[SerializeField] private bool _autoFixOffset = true;

		/// <summary>
		/// 单元格尺寸大小
		/// </summary>
		[SerializeField] private Vector2 _cellSize = Vector2.zero;

		/// <summary>
		/// 单元格边距大小
		/// </summary>
		[SerializeField] private RectOffset _cellPadding = null;

		[HideInInspector] public BindingInfo ScrollTypeBinding = new BindingInfo {
			// Inspecter Name
			BindingName = "ScrollType",
			// Properties are two way
			Filters = BindingFilter.Properties,
			// Filters Model Properties By Type
			FilterTypes = new[] { typeof(TScrollType) }
		};

		/// <summary>
		/// 行数.
		/// </summary>
		[SerializeField] private int _rowsNum = 0;
		/// <summary>
		/// 列数.
		/// </summary>
		[SerializeField] private int _colsNum = 0;

		/// <summary>
		/// 起始偏移.
		/// </summary>
		private Vector3 _contentStartOffset = Vector3.zero;

		/// <summary>
		/// 重利用视图信息.
		/// </summary>
		protected RecyleViewInfo _recyleViewInfo = null;

		/// <summary>
		/// 单元格列表.
		/// </summary>
		private List<RecyleCell> _cells = new List<RecyleCell> ();

		/// <summary>
		/// 当前Index(行或者列).
		/// </summary>
		private int _curDeltaIndex = -1;

		#endregion

        /// <summary>
        ///     Bottom Up as opposed to Top Down
        /// </summary>
        public bool SetAsFirstSibling = false;

        [HideInInspector] public BindingInfo SourceBinding = new BindingInfo {BindingName = "DataSource"};

        private void Awake()
        {
			_contentRectTrans = GetComponent<RectTransform>();
            Init();

            if (Application.isPlaying)
            {
				if (CellPrefab)
                {

					_cellRectTrans = CellPrefab.GetComponent<RectTransform>();

					var scale = CellPrefab.transform.localScale;
					CellPrefab.transform.SetParent(transform.parent);
					CellPrefab.SetActive(false);
					CellPrefab.transform.localScale = scale;

					if (CellPrefab.GetComponent<BindingContext>() == null)
                    {
                        Debug.LogError("template item must have an Root.");
                        enabled = false;
                    }
                }

                if (LoadingMask)
                    LoadingMask.SetActive(false);
            }
        }

        public override void Init()
        {
            if (IsInit)
                return;
			IsInit = true;

			ScrollTypeBinding.Action = SetScrollType;
			ScrollTypeBinding.ShouldShow = () => {
				return true;
			};

            SourceBinding.Action = UpdateSource;
            SourceBinding.Filters = BindingFilter.Properties;
            SourceBinding.FilterTypes = new[] {typeof (IEnumerable)};
        }

		/// <summary>
		/// 设定滚动类型
		/// </summary>
		/// <param name="value">Value.</param>
		protected void SetScrollType(object value) { 
			TScrollType scrollType = (TScrollType)value;

			// 初始化列表信息
			this.initScrollRectInfo(scrollType);

			// 注册滚动委托
			if (this._scrollRect != null) {
				this._scrollRect.onValueChanged.AddListener (OnScroll);
			}

		}

        protected void UpdateSource(object value)
        {
            if (OneTime && IsLoaded)
                return;

            if (DelayLoad)
                StartCoroutine(BindAsync(value));
            else
                Bind(value);
        }

        private IEnumerator BindAsync(object data)
        {
            yield return 1;
            Bind(data);
        }

        /// <summary>
        ///     Bind the ObservableCollection
        /// </summary>
        /// <param name="data"></param>
        public void Bind(object data)
        {
            if (DataList != null)
            {
                DataList.OnObjectAdd -= OnAdd;
//                DataList.OnObjectInsert -= OnInsert;
                DataList.OnClear -= OnClear;
//                DataList.OnObjectRemove -= OnRemove;
//                DataList.OnReplace -= OnReplace;
                DataList.OnSetFirst -= SetFirst;
//                DataList.OnDelet -= OnDelet;
            }

            foreach (var item in Children)
            {
                item.DataInstance = null;

                Recycle(item.gameObject);
            }


            DataList = null;
            OnClear();
            StopAllCoroutines();

            if (data is IObservableCollection)
            {
                DataList = data as IObservableCollection;
              

                StartCoroutine(AddAsync(DataList.GetObjects()));

                DataList.OnObjectAdd += OnAdd;
//                DataList.OnObjectInsert += OnInsert;
                DataList.OnClear += OnClear;
//                DataList.OnObjectRemove += OnRemove;
//                DataList.OnReplace += OnReplace;
                DataList.OnSetFirst += SetFirst;
//                DataList.OnDelet += OnDelet;
                IsLoaded = true;
            }
            else if (data is IEnumerable)
            {
                var a = data as IEnumerable;

                StartCoroutine(AddAsync(a.Cast<object>()));
                IsLoaded = true;
            }
        }

        private void OnClear()
        {
            foreach (var item in Children)
            {
                item.DataInstance = null;

                Recycle(item.gameObject);
            }

            Children.Clear();

            Datas.Clear();

			this._recyleViewInfo.ClearInfo (false);
			this._cells.Clear ();
			this._contentStartOffset = Vector3.zero;

            IsLoaded = false;
        }

//        private void OnRemove(object obj)
//        {
//            var view = Children.FirstOrDefault(o => o.DataInstance == obj);
//
//            if (view != null)
//            {  
//                view.DataInstance = null;
//
//                Children.Remove(view);
//
//                Recycle(view.gameObject);
//            }
//        }

//        private void OnDelet(object obj)
//        {
//            var view = Children.FirstOrDefault(o => o.DataInstance == obj);
//            if (view != null)
//            {
//                view.DataInstance = null;
//
//                Children.Remove(view);
//
//                Recycle(view.gameObject);
//            }
//            if (Datas.ContainsKey(obj))
//            {
//
//                Datas.Remove(Datas[obj]);
//
//                Children.Remove(Datas[obj]);
//              
//                Recycle(Datas[obj].gameObject);
//            }
//        }

        private void OnAdd(object obj)
        {
			if ((this._recyleViewInfo == null) || (this._cells == null)) {
				return;
			}
				
			int recyleCellIndex = this.GetRecyleCellIndex (CellIndex);
			int cellsCount = (this._recyleViewInfo.CellsCount + 1);

			// 重置单元格
			this.ResetContentSizeByCellsCount (cellsCount);

			GameObject cell = null;
			RecyleCell recyleCellInfo = null;

			// 已经创建
			if (this.IsRecyleCellCreatedAlready (recyleCellIndex, ref recyleCellInfo) == true) {

				recyleCellInfo.Index = CellIndex;
				cell = recyleCellInfo.Cell;

				// 首次创建
			} else {
				cell = GetNext ();
					
				RecyleCell cellInfo = new RecyleCell ();
				cellInfo.Index = CellIndex;
				cellInfo.RecyleIndex = recyleCellIndex;
				cellInfo.Cell = cell;
				this._cells.Add (cellInfo);

			}

			// 设置名字已经坐标位置
			if (cell != null) {

				var root = cell.GetComponent<BindingContext> ();

				root.DataInstance = obj;

				Children.Add (root);

				RecyleBindingData data = new RecyleBindingData ();
				data.Index = CellIndex;
				data.Binder = root;
				data.Data = obj;
				Datas.Add (CellIndex, data);

				cell.name = string.Format ("_Cell_{0}_{1}", recyleCellIndex, CellIndex);

				if (SetAsFirstSibling) {
					cell.transform.SetAsFirstSibling ();
				}

				// 坐标
				Vector3 posTmp;
				if (this._recyleViewInfo.GetCellPos (CellIndex, out posTmp) == true) {

					(cell.transform as RectTransform).anchoredPosition = posTmp;
				}
			}

			++CellIndex;
        }

//        private void OnInsert(int location, object obj)
//        {
//			var view = GetNext();
//
//            var root = view.GetComponent<BindingContext>();
//
//            root.DataInstance = obj;
//
//			view.name = "_Item " + CellIndex++;
//
//            Children.Insert(location, root);
//
//            KeyValuePair<object, BindingContext> temp = new KeyValuePair<object, BindingContext>(obj, root);
//
//            Datas.ToList().Insert(location, temp);
//
//            if (SetAsFirstSibling)
//                view.transform.SetSiblingIndex(location);
//        }

//        private void OnReplace(object oldobj, object newobj)
//        {
//            var view = Children.FirstOrDefault(o => o.DataInstance == oldobj);
//
//            if (view != null)
//            {   
//                view.DataInstance = newobj;
//
//              //  Children.Remove(view);
//
//              //  Recycle(view.gameObject);
//            }
//
//            //Debug.Log(Datas.Count);
//            //Debug.Log("no find");
//            if (Datas.ContainsKey(oldobj))
//            {
//                Datas[oldobj].DataInstance = newobj;
//                Datas.Add(newobj, Datas[oldobj]);
//                Datas.Remove(oldobj);
//            }
//        }

        private IEnumerator AddAsync(IEnumerable<object> objects)
        {
            if (LoadingMask)
                LoadingMask.SetActive(true);

            foreach (var obj in objects)
            {
                OnAdd(obj);
            }

            if (LoadingMask)
                LoadingMask.SetActive(false);

            yield return 1;
        }

        private void SetFirst(object o)
        {
			foreach (KeyValuePair<int, RecyleBindingData> item in this.Datas) {
				if (item.Value.Data.Equals (o) == true) {
					item.Value.Binder.gameObject.transform.SetAsFirstSibling ();
					break;
				}
			}
        }

		private GameObject GetNext()
        {
			if (_contentRectTrans && _cellRectTrans)
            {
                //var next = Instantiate(Prefab, RectTransform.position, RectTransform.rotation) as GameObject;
                //var rect = next.GetComponent<RectTransform>();
                //rect.parent = RectTransform;
                //// idk, scale sometimes goes wierd
                //rect.localScale = _cellRectTrans.localScale;
                //next.SetActive(true);
                //return next;

				var next = Instantiate(CellPrefab, _contentRectTrans.position, _contentRectTrans.rotation) as GameObject;
				next.transform.SetParent(_contentRectTrans);

                // idk, scale sometimes goes wierd
                next.transform.localScale = _cellRectTrans.localScale;
                next.SetActive(true);
                return next;
            }
            else
            {
				var next = Instantiate(CellPrefab, transform.position, transform.rotation) as GameObject;
				next.transform.SetParent(_contentRectTrans);

                // idk, scale sometimes goes wierd
				next.transform.localScale = CellPrefab.transform.localScale;
                next.SetActive(true);
                return next;
            }
        }

        private void Recycle(GameObject instance)
        {
            Destroy(instance);
        }

		#region 重利用列表 - 接口追加
		/// <summary>
		/// 初始化滚动区域信息.
		/// </summary>
		private void initScrollRectInfo(TScrollType iScrollType) {
			Rect displayRect = this._scrollRect.gameObject.GetComponent<RectTransform> ().rect;

			// 初始化视频信息
			this._recyleViewInfo = RecyleViewInfo.Create (
				iScrollType, this._isOrderByAsc,
				this._colsNum, this._rowsNum,
				displayRect.size, this._viewPadding);
			this._recyleViewInfo.initByCellInfo (
				this._cellSize,
				(this._cellRectTrans.anchorMin + this._cellRectTrans.anchorMax) / 2,
				this._cellRectTrans.pivot, this._cellPadding);
		}

		/// <summary>
		/// 视图滚动委托.
		/// </summary>
		/// <param name="iDelta">I delta.</param>
		protected void OnScroll(Vector2 iDelta) {
			Vector3 curContentOffset = this.transform.localPosition;
			//  相对滚动
			Vector3 relativeScrollOffset = curContentOffset - this._contentStartOffset;
			if ((relativeScrollOffset.x == 0.0f) && 
				(relativeScrollOffset.y == 0.0f) && 
				(relativeScrollOffset.x == 0.0f)) {
				return;
			}
			if (this._recyleViewInfo == null) {
				return;
			}

			// 尚未超过重利用总数，则不做重利用处理
			if (this._recyleViewInfo.CellsCount <= this._recyleViewInfo.RecyleCellsCount) {
				return;
			}

			if (this._recyleViewInfo.IsBoth) {
				Debug.LogError ("The scroll type of recyleview has not been supported yet!!!");
				return;
			}

			int curDeltaIndex = this.GetCurDeltaIndexByOffset (relativeScrollOffset);
			if (this._curDeltaIndex == -1) {
				this._curDeltaIndex = curDeltaIndex;
			}

			if (curDeltaIndex != this._curDeltaIndex) {

				this.ScrollToNext (curDeltaIndex - this._curDeltaIndex);
				this._curDeltaIndex = curDeltaIndex;
			}

		}

		/// <summary>
		/// 回滚到下一个.
		/// </summary>
		/// <param name="iDeltaIndex">I delta index.</param>
		private void ScrollToNext(int iDeltaIndex) {

			int recyleCellsCount = this._recyleViewInfo.RecyleRowsNum * this._recyleViewInfo.ViewColsNum;

			// 向上或者向右
			if (iDeltaIndex > 0) {
				if (this._recyleViewInfo.IsHorizontal) {
				
				} else if (this._recyleViewInfo.IsVertical) {
				
					int StartIndex = this.GetCurMinDeltaIndex ();
					int EndIndex = StartIndex + this._recyleViewInfo.ViewColsNum;
					for (int index = StartIndex; index < EndIndex; ++index) {
						RecyleCell cellInfoTmp = this.GetRecyleCellInfo (index);

						int toCellIndex = index - 1;
						toCellIndex += recyleCellsCount;

						this.ResetRecyleCell (cellInfoTmp, toCellIndex);
					}
				}
			
				// 向下或者向左
			} else if (iDeltaIndex < 0) {

				if (this._recyleViewInfo.IsHorizontal) {
				} else if (this._recyleViewInfo.IsVertical) {
					int StartIndex = this.GetCurMaxDeltaIndex ();
					int EndIndex = StartIndex + this._recyleViewInfo.ViewColsNum;
					for (int index = StartIndex; index < EndIndex; ++index) {
						RecyleCell cellInfoTmp = this.GetRecyleCellInfo (index);

						int toCellIndex = index + 1;

						toCellIndex -= recyleCellsCount;

						this.ResetRecyleCell (cellInfoTmp, toCellIndex);
					}
				}

			}

		}

		private void ResetRecyleCell(RecyleCell iCellInfo, int iToCellIndex) {
			if (iCellInfo == null) {
				return;
			}
			if (this.Datas.ContainsKey (iToCellIndex) == true) {
				
				iCellInfo.Cell.name = string.Format ("_Cell_{0}_{1}", iCellInfo.RecyleIndex, iToCellIndex);

				BindingContext Binder = iCellInfo.Cell.GetComponent<BindingContext> ();

				Binder.DataInstance = this.Datas[iToCellIndex].Data;

				iCellInfo.Index = iToCellIndex;

				// 坐标
				Vector3 posTmp;
				if (this._recyleViewInfo.GetCellPos (iToCellIndex, out posTmp) == true) {

					(iCellInfo.Cell.transform as RectTransform).anchoredPosition = posTmp;
				}
			}
		}

		private RecyleCell GetRecyleCellInfo(int iIndex) {
		
			foreach (RecyleCell cell in this._cells) {
				if (iIndex == cell.Index) {
					return cell;
				}
			}
			return null;
		}

		private int GetCurMaxDeltaIndex() {
			int intRet = 0;

			int cellIndex = -1;
			RecyleCell maxCell = null;
			foreach (RecyleCell cell in this._cells) {
				if (-1 == cellIndex) {
					cellIndex = cell.Index;
				}
				if (cell.Index < cellIndex) {
					continue;
				}
				maxCell = cell;
			}
			return ((maxCell != null) ? maxCell.Index : intRet);
			
		}

		private int GetCurMinDeltaIndex() {
			int intRet = 0;

			int cellIndex = -1;
			RecyleCell minCell = null;
			foreach (RecyleCell cell in this._cells) {
				if (-1 == cellIndex) {
					cellIndex = cell.Index;
				}
				if (cell.Index > cellIndex) {
					continue;
				}
				minCell = cell;
			}
			return ((minCell != null) ? minCell.Index : intRet);
		}

		private int GetCurDeltaIndexByOffset(Vector3 iRelativeScrollOffset) {
		
			int sign = this._isOrderByAsc ? 1 : -1;
			int deltaIndex = 0;
			if (this._recyleViewInfo.IsHorizontal) {
				// 向左
				if (iRelativeScrollOffset.x < 0.0f) {
					iRelativeScrollOffset.x += this._recyleViewInfo.ViewPadding.bottom; 
					// 向右
				} else {
					iRelativeScrollOffset.x -= this._recyleViewInfo.ViewPadding.top;
				}
				iRelativeScrollOffset.y = 0.0f;

				int distance = (int)iRelativeScrollOffset.x;
				float cellTotalWidth_f = this._recyleViewInfo.CellPadding.left;
				cellTotalWidth_f += this._recyleViewInfo.CellWidth;
				cellTotalWidth_f += this._recyleViewInfo.CellPadding.right;
				int cellTotalWidth_i = (int)cellTotalWidth_f;

				deltaIndex = distance / cellTotalWidth_i;
			}

			if (this._recyleViewInfo.IsVertical) {
				iRelativeScrollOffset.x = 0.0f;
				// 向上
				if (iRelativeScrollOffset.y < 0.0f) {
					iRelativeScrollOffset.y += this._recyleViewInfo.ViewPadding.bottom; 
					// 向下
				} else {
					iRelativeScrollOffset.y -= this._recyleViewInfo.ViewPadding.top;
				}

				int distance = (int)iRelativeScrollOffset.y;
				float cellTotalHeight_f = this._recyleViewInfo.CellPadding.top;
				cellTotalHeight_f += this._recyleViewInfo.CellHeight;
				cellTotalHeight_f += this._recyleViewInfo.CellPadding.bottom;
				int cellTotalHeight_i = (int)cellTotalHeight_f;

				deltaIndex = distance / cellTotalHeight_i;
			}

			deltaIndex *= sign;
			Debug.LogFormat ("GetDeltaIndexByOffset:{0} ------ {1}", deltaIndex,  iRelativeScrollOffset.ToString());
			return deltaIndex;

		}

		/// <summary>
		/// 检测当前单元格是否已经被创建.
		/// </summary>
		/// <returns><c>true</c> 已经创建; 尚未创建, <c>false</c>.</returns>
		/// <param name="iRecyleCellIndex">重利用单元格Index.</param>
		/// <param name="iRecyleCellInfo">重利用单元格信息.</param>
		private bool IsRecyleCellCreatedAlready(int iRecyleCellIndex, ref RecyleCell iRecyleCellInfo) {
		
			RecyleCell[] cellsTmp = this._cells
				.Where (o => (o.RecyleIndex == iRecyleCellIndex)).ToArray ();
			if ((cellsTmp != null) && (cellsTmp.Length == 1)) {
				iRecyleCellInfo = cellsTmp [0];
				return true;
			}
			return false;
		}

		/// <summary>
		/// 取得重利用.
		/// </summary>
		/// <returns>The recyle cell index.</returns>
		/// <param name="iCellIndex">I cell index.</param>
		private int GetRecyleCellIndex(int iCellIndex) {
			if (this._recyleViewInfo == null) {
				return iCellIndex;
			}
			return (iCellIndex % this._recyleViewInfo.RecyleCellsCount);
		}

		/// <summary>
		/// 重置尺寸.
		/// </summary>
		/// <param name="iCellsCount">单元格总数.</param>
		private void ResetContentSizeByCellsCount (int iCellsCount) {
			if (this._recyleViewInfo == null) {
				return;
			}
			if (this._recyleViewInfo.ResetContentSizeByCellsCount (iCellsCount) == true) {

				// 重置当前各个单元格坐标位置
				foreach (RecyleCell cellInfo in this._cells) {
					Vector3 cellPos;
					if (this._recyleViewInfo.GetCellPos (cellInfo.Index, out cellPos) == true) {
						(cellInfo.Cell.transform as RectTransform).anchoredPosition = cellPos;
					}
				}

				// 重置Content Size
				RectTransform rectTran = this.GetComponent<RectTransform> ();
				if (rectTran != null) {
					
					rectTran.sizeDelta = this._recyleViewInfo.ContentSize;
				}

				// 重置Content Offset
				if (this._autoFixOffset == true) {
					(this.transform as RectTransform).anchoredPosition = this._recyleViewInfo.ContentStartOffset;
				}

				// 起始位置
				this._contentStartOffset = this.transform.localPosition;
			}
		}

		#endregion
    }
}