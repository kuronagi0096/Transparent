#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE); // ウィンドウモードにする（デフォはフルスクリーン）
    if (DxLib_Init() == -1) return -1; // DXライブラリ初期化

    DrawString(100, 100, "Hello DXライブラリ！", GetColor(255, 255, 255));

    WaitKey(); // キー入力待ち
    DxLib_End(); // DXライブラリ終了

    return 0;
}
