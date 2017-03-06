using System;
using System.Linq;
using System.Collections;

using UnityEngine;
using Foundation.Databinding;

namespace NFF
{
	[System.Serializable]
	public class CellSize {

		public CellSize() {
			this.Width = 0.0f;
			this.Height = 0.0f;
		}
		public CellSize(float iWidth, float iHeight) {
			this.Width = iWidth;
			this.Height = iHeight;
			
		}
		private Vector2 _size = new Vector2(0.0f, 0.0f);
		/// <summary>
		/// 宽度.
		/// </summary>
		/// <value>宽度.</value>
		public float Width {
			get { return this._size.x; }
			set { this._size.x = value; }
		}

		/// <summary>
		/// 高度.
		/// </summary>
		/// <value>高度.</value>
		public float Height {
			get { return this._size.y; }
			set { this._size.y = value; }
		}
	}

	/// <summary>
	/// Recyle scroll cell.
	/// </summary>
	[System.Serializable]
	[ExecuteInEditMode]
	public abstract class RecyleCellBinder : BindingBase {

		/// <summary>
		/// 单元格Index.
		/// </summary>
		/// <value>单元格Index.</value>
		public int CellIndex {
			get;
			set;
		}

		/// <summary>
		/// 内容Index.
		/// </summary>
		/// <value>内容Index.</value>
		public int ContentIndex {
			get;
			set;
		}

		/// <summary>
		/// Gets or sets the size of cell.
		/// </summary>
		/// <value>The size of cell.</value>
		private CellSize _size = new CellSize();
		public CellSize Size {
			get { return this._size; }
			set { this._size = value; }
		}
		/// <summary>
		/// 宽度.
		/// </summary>
		/// <value>宽度.</value>
		public float Width {
			get { return this.Size.Width; }
		}

		/// <summary>
		/// 高度.
		/// </summary>
		/// <value>高度.</value>
		public float Height {
			get { return this.Size.Height; }
		}

		void Awake() {
			this.Init ();
		}

		/// <summary>
		/// 初始化
		/// </summary>
		/// <remarks>Add Bindings</remarks>
		public override void Init() {

			// 初始化尺寸
			this.initSizeInfo();
			// 初始化Cell
			this.InitCell ();
		}

		/// <summary>
		/// 初始化尺寸.
		/// </summary>
		private void initSizeInfo() {
			RectTransform rectInfo = this.GetComponent<RectTransform> ();
			if (rectInfo != null) {
				Size.Width = rectInfo.rect.size.x;
				Size.Height = rectInfo.rect.size.y;
			}
		}

		/// <summary>
		/// 初始化Cell
		/// </summary>
		public abstract void InitCell ();

		/// <summary>
		/// 重置单元格尺寸（当View尺寸与单元格尺寸冲突时，以View尺寸为准，重置单元尺寸）.
		/// </summary>
		/// <param name="iContentSize">I content size.</param>
		public void ResetContentSize (Vector2 iContentSize) {
			RectTransform cellRectTran = this.GetComponent<RectTransform> ();
			if (cellRectTran != null) {
				Vector2 curSize = cellRectTran.sizeDelta;
				if (iContentSize.Equals (curSize) == true) {
					return;
				}
				float scaleX = iContentSize.x / curSize.x;
				float scaleY = iContentSize.y / curSize.y;
				cellRectTran.transform.localScale = new Vector3 (scaleX, scaleY, 1.0f);
			}
		}

		/// <summary>
		/// 用iContentIndex的内容，重置iIndex的cell .
		/// </summary>
		/// <param name="iCellIndex">单元格Index.</param>
		/// <param name="iContentIndex">内容index.</param>
		public abstract void ResetCell (int iCellIndex, int iContentIndex);

		[ContextMenu("ShowDebugInfo")]
		protected virtual void ShowDebugInfo() {
			Debug.LogFormat ("CellSize(w:{0} h:{1}) CellIndex:{2} ContentIndex:{3}", 
				this.Width, this.Height, this.CellIndex, this.ContentIndex);
		}
	}
}