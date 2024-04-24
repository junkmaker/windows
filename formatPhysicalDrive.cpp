#include <windows.h>
#include <virtdisk.h>
#include <iostream>

#pragma comment(lib, "virtdisk.lib")

int main() {
    // PhysicalDrive番号を指定します。例えば、'1'
    int driveNumber = 1;

    // ドライブパスを作成します。例えば、"\\\\.\\PhysicalDrive1"
    std::wstring drivePath = L"\\\\.\\PhysicalDrive" + std::to_wstring(driveNumber);

    // VIRTUAL_STORAGE_TYPE 構造体を初期化します
    VIRTUAL_STORAGE_TYPE storageType;
    storageType.DeviceId = VIRTUAL_STORAGE_TYPE_DEVICE_VHD;
    storageType.VendorId = VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT;

    // フォーマットパラメータを設定します
    CREATE_VIRTUAL_DISK_PARAMETERS parameters;
    parameters.Version = CREATE_VIRTUAL_DISK_VERSION_1;
    parameters.Version1.UniqueId = GUID();
    parameters.Version1.MaximumSize = 0;
    parameters.Version1.BlockSizeInBytes = 0;
    parameters.Version1.SectorSizeInBytes = 512;
    parameters.Version1.ParentPath = NULL;
    parameters.Version1.SourcePath = NULL;
    parameters.Version1.OpenFlags = OPEN_VIRTUAL_DISK_FLAG_NONE;
    parameters.Version1.GetInfoOnly = FALSE;

    // ハンドルを初期化します
    HANDLE vhdHandle = NULL;

    // 仮想ディスクを作成します
    DWORD status = CreateVirtualDisk(
        &storageType,
        drivePath.c_str(),
        VIRTUAL_DISK_ACCESS_ALL,
        NULL,
        CREATE_VIRTUAL_DISK_FLAG_NONE,
        0,
        &parameters,
        NULL,
        &vhdHandle
    );

    if (status == ERROR_SUCCESS) {
        std::wcout << L"ドライブのフォーマットに成功しました。\n";
    } else {
        std::wcout << L"ドライブのフォーマットに失敗しました。エラーコード: " << status << L"\n";
    }

    // ハンドルを閉じます
    if (vhdHandle != NULL) {
        CloseHandle(vhdHandle);
    }

    return 0;
}
