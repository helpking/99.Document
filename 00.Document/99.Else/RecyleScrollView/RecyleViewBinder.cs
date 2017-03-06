using UnityEngine;
using UnityEngine.UI;
using System.Linq;
using System.Collections;
using Foundation.Databinding;

namespace NFF
{
	/// <summary>
	/// 滚动类型.
	/// </summary>
	public enum TScrollType {
		/// <summary>
		/// 横向.
		/// </summary>
		kHorizontal,
		/// <summary>
		/// 纵向.
		/// </summary>
		kVeritcal,
		/// <summary>
		/// 双向.
		/// </summary>
		kBoth,
		/// <summary>
		/// 默认.
		/// </summary>
		kDefault = kVeritcal
	}

	[AddComponentMenu("NFF/RecyleScrollView/RecyleViewBinder")]
	[System.Serializable]
	[ExecuteInEditMode]
	public class RecyleViewBinder : BindingBase {

		[HideInInspector] public BindingInfo ScrollTypeBinding = new BindingInfo {
			// Inspecter Name
			BindingName = "ScrollType",
			// Properties are two way
			Filters = BindingFilter.Properties,
			// Filters Model Properties By Type
			FilterTypes = new[] { typeof(TScrollType) }
		};

		void Awake() {

			ScrollTypeBinding.Action = SetScrollType;
			ScrollTypeBinding.ShouldShow = () => {
				return true;
			};

		}

		/// <summary>
		/// 初始化
		/// </summary>
		/// <remarks>Add Bindings</remarks>
		public override void Init() {
		}

		/// <summary>
		/// 设定滚动类型
		/// </summary>
		/// <param name="value">Value.</param>
		protected void SetScrollType(object value) {
			TScrollType scrollType = (TScrollType)value;
			ScrollRect scrollRect = this.GetComponent<ScrollRect> ();
			if (scrollRect == null) {
				return;
			}
			if ((TScrollType.kHorizontal == scrollType) ||
			    (TScrollType.kBoth == scrollType)) {
				scrollRect.horizontal = true;
			} else {
				scrollRect.horizontal = false;
			}

			if ((TScrollType.kVeritcal == scrollType) ||
				(TScrollType.kBoth == scrollType)) {
				scrollRect.vertical = true;
			} else {
				scrollRect.vertical = false;
			}
		}

	}
}
