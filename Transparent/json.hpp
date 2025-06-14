#pragma once
#include <variant>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace MyJson {

    class JsonValue;

    using JsonObject = std::map<std::string, JsonValue>;
    using JsonArray = std::vector<JsonValue>;

    class JsonValue {
    public:
        using Value = std::variant<std::nullptr_t, bool, int, double, std::string, JsonObject, JsonArray>;

        JsonValue() : value_(nullptr) {}
        JsonValue(bool b) : value_(b) {}
        JsonValue(int i) : value_(i) {}
        JsonValue(double d) : value_(d) {}
        JsonValue(const std::string& s) : value_(s) {}
        JsonValue(const char* s) : value_(std::string(s)) {}
        JsonValue(const JsonObject& obj) : value_(obj) {}
        JsonValue(const JsonArray& arr) : value_(arr) {}

        bool IsNull() const { return std::holds_alternative<std::nullptr_t>(value_); }
        bool IsBool() const { return std::holds_alternative<bool>(value_); }
        bool IsInt() const { return std::holds_alternative<int>(value_); }
        bool IsDouble() const { return std::holds_alternative<double>(value_); }
        bool IsString() const { return std::holds_alternative<std::string>(value_); }
        bool IsObject() const { return std::holds_alternative<JsonObject>(value_); }
        bool IsArray() const { return std::holds_alternative<JsonArray>(value_); }

        bool AsBool() const { return std::get<bool>(value_); }
        int AsInt() const { return std::get<int>(value_); }
        double AsDouble() const { return std::get<double>(value_); }
        const std::string& AsString() const { return std::get<std::string>(value_); }
        const JsonObject& AsObject() const { return std::get<JsonObject>(value_); }
        const JsonArray& AsArray() const { return std::get<JsonArray>(value_); }

        std::string ToString(int indent = 0) const {
            std::ostringstream oss;
            std::string tab(indent, ' ');
            if (IsNull()) oss << "null";
            else if (IsBool()) oss << (AsBool() ? "true" : "false");
            else if (IsInt()) oss << AsInt();
            else if (IsDouble()) oss << AsDouble();
            else if (IsString()) oss << "\"" << AsString() << "\"";
            else if (IsArray()) {
                oss << "[";
                for (const auto& item : AsArray()) {
                    oss << item.ToString(indent + 2) << ",";
                }
                oss << "]";
            }
            else if (IsObject()) {
                oss << "{";
                for (const auto& [k, v] : AsObject()) {
                    oss << "\"" << k << "\":" << v.ToString(indent + 2) << ",";
                }
                oss << "}";
            }
            return oss.str();
        }

    private:
        Value value_;
    };

    // --- ファイル入出力関数 (簡易版) ---
    inline void SaveJsonToFile(const JsonValue& value, const std::string& filepath) {
        std::ofstream ofs(filepath);
        ofs << value.ToString();
    }

    inline JsonValue LoadJsonFromFile(const std::string& filepath) {
        std::ifstream ifs(filepath);
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        // パース機能を自作したい場合は ParseJson(buffer.str()) をここに
        return JsonValue(); // 仮戻り値（未実装）
    }

}
