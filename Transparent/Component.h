#pragma once
#include "Actor.h"

class Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="owner">コンポーネントを所有させるアクター</param>
	/// <param name="updateOrder">コンポーネントの更新順序。値が小さいほど早く更新される</param>
	Component(Actor* owner, int updateOrder = 100);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Component();

	/// <summary>
	/// コンポーネントをデルタタイムで更新する
	/// </summary>
	/// <param name="deltaTime">更新速度</param>
	virtual void UpdateComponent(float deltaTime);

	void SetEnabled(bool enabled);/// コンポーネントを有効にするかどうか設定する
	void GetEnabled() const;/// コンポーネントが有効かどうか取得する

	/// <summary>
	/// 更新順序を取得	
	/// </summary>
	/// <returns>更新順序番号：デフォルト100</returns>
	int GetUpdateOrder() const;

protected:
	Actor* _owner;/// コンポーネントを所有しているアクター
	int _updateOrder;/// コンポーネントの更新順序
	bool _isEnabled;/// コンポーネントが有効かどうか
};

