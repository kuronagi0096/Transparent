#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɂ���i�f�t�H�̓t���X�N���[���j
    if (DxLib_Init() == -1) return -1; // DX���C�u����������

    DrawString(100, 100, "Hello DX���C�u�����I", GetColor(255, 255, 255));

    WaitKey(); // �L�[���͑҂�
    DxLib_End(); // DX���C�u�����I��

    return 0;
}
