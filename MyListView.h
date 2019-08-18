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
	// スクロール同期を行う処理を追加
	public ref class MyListView : public System::Windows::Forms::ListView
	{
	public:
		// コンストラクタ
		MyListView()
		{
			//View = System::Windows::Forms::View::Details; // Details限定
			// 同期対象のListView
			mVScrollSynchronizedListView = nullptr;
			// スクロール情報
			mOldScrollY = 0;		// 垂直方向旧位置
			mSyncScroll = false;	// 同期状態
		}

		// 垂直スクロールを同期させるリストビュー
		[CategoryAttribute("特殊")]
		[DescriptionAttribute("垂直スクロール同期するリストビューを指定")]
		property MyListView^ VScrollSynchronizedListView
		{
			MyListView^ get() {
				return mVScrollSynchronizedListView;
			}
			void set(MyListView^ listView) {
				mVScrollSynchronizedListView = listView;
			}
		}

		// 垂直スクロール旧位置
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

		// 連動スクロール開始
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

		// 連動スクロール用イベント処理
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
							// 同期対象にスクロールメッセージを送信
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
