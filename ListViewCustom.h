#pragma once

namespace Project1 {

	using namespace System::Windows::Forms;

	//  ListView���p�������N���X
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
		//			"�����X�N���[���o�[���X�N���[������܂����B");
		//		break;
		//	case WM_VSCROLL:
		//		Console.WriteLine(
		//			"�����X�N���[���o�[���X�N���[������܂����B");
		//		break;
		//	}
		//	base.WndProc(ref m);
		//}
	};
}
