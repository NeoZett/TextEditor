#pragma once

#include <filesystem>
#include <optional>
#include <string>

class FileService
{
public:
    static std::wstring ReadAllText(
        const std::filesystem::path& filePath);

    static void WriteAllText(
        const std::filesystem::path& filePath,
        const std::wstring& content);

    static bool Exists(
        const std::filesystem::path& filePath);
};