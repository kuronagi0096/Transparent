#pragma once
#include "Component.h"
#include "unordered_set"

/**
 * @class GameObject
 * @brief ゲーム内のオブジェクトを表すクラス。
 *
 * GameObject は複数のコンポーネントを持つことができ、これにより
 * 様々な機能を動的に追加・削除することが可能です。
 */
class GameObject {
public:
    /**
     * @brief コンポーネントを GameObject に追加します。
     *
     * @param component 追加するコンポーネントへのポインタ。
     *                  コンポーネントは GameObject に関連付けられます。
     */
    void AddComponent(Component* component);

    /**
     * @brief GameObject からコンポーネントを削除します。
     *
     * @param component 削除するコンポーネントへのポインタ。
     *                  コンポーネントが存在しない場合は何もしません。
     */
    void RemoveComponent(Component* component);

private:
    /**
     * @brief GameObject に関連付けられているコンポーネントの集合。
     *
     * コンポーネントはポインタとして管理され、重複を防ぐために
     * std::unordered_set を使用しています。
     */
    std::unordered_set<Component*> _components;
};
