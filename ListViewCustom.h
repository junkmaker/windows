#pragma once

namespace Project1 {

	using namespace System::Windows::Forms;

	//  ListViewを継承したクラス
	ref class ListViewCustom :
		public ListView
	{
	protected:
		//protected override void  WndProc(ref Message m)
		//{
		//	const int WM_HSCROLL = 0x114;
		//	const int WM_VSCROLL = 0x115;

		//	switch (m.Msg)
		//	{
		//	case WM_HSCROLL:
		//		Console.WriteLine(
		//			"水平スクロールバーがスクロールされました。");
		//		break;
		//	case WM_VSCROLL:
		//		Console.WriteLine(
		//			"垂直スクロールバーがスクロールされました。");
		//		break;
		//	}
		//	base.WndProc(ref m);
		//}
	};
}
