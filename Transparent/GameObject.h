#pragma once
#include "Component.h"
#include "unordered_set"

/**
 * @class GameObject
 * @brief �Q�[�����̃I�u�W�F�N�g��\���N���X�B
 *
 * GameObject �͕����̃R���|�[�l���g�������Ƃ��ł��A����ɂ��
 * �l�X�ȋ@�\�𓮓I�ɒǉ��E�폜���邱�Ƃ��\�ł��B
 */
class GameObject {
public:
    /**
     * @brief �R���|�[�l���g�� GameObject �ɒǉ����܂��B
     *
     * @param component �ǉ�����R���|�[�l���g�ւ̃|�C���^�B
     *                  �R���|�[�l���g�� GameObject �Ɋ֘A�t�����܂��B
     */
    void AddComponent(Component* component);

    /**
     * @brief GameObject ����R���|�[�l���g���폜���܂��B
     *
     * @param component �폜����R���|�[�l���g�ւ̃|�C���^�B
     *                  �R���|�[�l���g�����݂��Ȃ��ꍇ�͉������܂���B
     */
    void RemoveComponent(Component* component);

private:
    /**
     * @brief GameObject �Ɋ֘A�t�����Ă���R���|�[�l���g�̏W���B
     *
     * �R���|�[�l���g�̓|�C���^�Ƃ��ĊǗ�����A�d����h�����߂�
     * std::unordered_set ���g�p���Ă��܂��B
     */
    std::unordered_set<Component*> _components;
};
