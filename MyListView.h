#pragma once

#define WIN32_LEAN_AND_MEAN
#pragma comment(lib, "user32.lib")
#include <windows.h>
#include <CommCtrl.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

namespace MyControls {
	// �X�N���[���������s��������ǉ�
	public ref class MyListView : public System::Windows::Forms::ListView
	{
	public:
		// �R���X�g���N�^
		MyListView()
		{
			//View = System::Windows::Forms::View::Details; // Details����
			// �����Ώۂ�ListView
			mVScrollSynchronizedListView = nullptr;
			// �X�N���[�����
			mOldScrollY = 0;		// �����������ʒu
			mSyncScroll = false;	// �������
		}

		// �����X�N���[���𓯊������郊�X�g�r���[
		[CategoryAttribute("����")]
		[DescriptionAttribute("�����X�N���[���������郊�X�g�r���[���w��")]
		property MyListView^ VScrollSynchronizedListView
		{
			MyListView^ get() {
				return mVScrollSynchronizedListView;
			}
			void set(MyListView^ listView) {
				mVScrollSynchronizedListView = listView;
			}
		}

		// �����X�N���[�����ʒu
		[BrowsableAttribute(false)]
		property int OldScrollY
		{
			int get() {
				return mOldScrollY;
			}
			void set(int pos) {
				mOldScrollY = pos;
			}
		}

		// �A���X�N���[���J�n
		[BrowsableAttribute(false)]
		property bool SyncScroll
		{
			bool get() {
				return mSyncScroll;
			}
			void set(bool isSync) {
				mSyncScroll = isSync;
			}
		}

	protected:

		// �A���X�N���[���p�C�x���g����
		virtual void WndProc(Message %m) override
		{
			ListView::WndProc(m);

			if (mSyncScroll	&& m.Msg == WM_PAINT) {
				SCROLLINFO si;
				ZeroMemory(&si, sizeof(SCROLLINFO));
				si.cbSize = sizeof(SCROLLINFO);
				si.fMask = SIF_POS;

				if (Items->Count
					&& ::GetScrollInfo((HWND)Handle.ToPointer(), SB_VERT, &si)) {
					if (mOldScrollY != si.nPos) {
						if (mVScrollSynchronizedListView) {
							int dx = 0;
							int dy = (si.nPos - mOldScrollY) * Items[0]->Bounds.Height;
							// �����ΏۂɃX�N���[�����b�Z�[�W�𑗐M
							mVScrollSynchronizedListView->OldScrollY = si.nPos;
							::SendMessage((HWND)mVScrollSynchronizedListView->Handle.ToPointer(), LVM_SCROLL, (WPARAM)dx, (LPARAM)dy);
						}
					}
					mOldScrollY = si.nPos;
				}
			}
		}

	private:

		MyListView^ mVScrollSynchronizedListView;
		bool        mSyncScroll;
		int         mOldScrollY;
	};
}
