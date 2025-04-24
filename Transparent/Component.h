#pragma once
#include "Actor.h"

class Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="owner">�R���|�[�l���g�����L������A�N�^�[</param>
	/// <param name="updateOrder">�R���|�[�l���g�̍X�V�����B�l���������قǑ����X�V�����</param>
	Component(Actor* owner, int updateOrder = 100);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Component();

	/// <summary>
	/// �R���|�[�l���g���f���^�^�C���ōX�V����
	/// </summary>
	/// <param name="deltaTime">�X�V���x</param>
	virtual void UpdateComponent(float deltaTime);

	void SetEnabled(bool enabled);/// �R���|�[�l���g��L���ɂ��邩�ǂ����ݒ肷��
	void GetEnabled() const;/// �R���|�[�l���g���L�����ǂ����擾����

	/// <summary>
	/// �X�V�������擾	
	/// </summary>
	/// <returns>�X�V�����ԍ��F�f�t�H���g100</returns>
	int GetUpdateOrder() const;

protected:
	Actor* _owner;/// �R���|�[�l���g�����L���Ă���A�N�^�[
	int _updateOrder;/// �R���|�[�l���g�̍X�V����
	bool _isEnabled;/// �R���|�[�l���g���L�����ǂ���
};

