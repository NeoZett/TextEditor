#include "pch.h"
#include "FileService.h"

#include <fstream>
#include <sstream>
#include <Windows.h>

bool FileService::Exists(const std::filesystem::path& filePath)
{
	return std::filesystem::exists(filePath);
}

std::wstring FileService::ReadAllText(const std::filesystem::path& filePath)
{
	std::ifstream file(filePath, std::ios::binary);
	if (!file.is_open())
	{
		return L"";
	}

	std::ostringstream ss;
	ss << file.rdbuf();

	std::string content = ss.str();

	// Convert UTF-8 (common for editors) to UTF-16 (WinUI uses wide strings)
	int size_needed = MultiByteToWideChar(
		CP_UTF8,
		0,
		content.c_str(),
		(int)content.size(),
		nullptr,
		0
	);

	std::wstring result(size_needed, 0);

	MultiByteToWideChar(
		CP_UTF8,
		0,
		content.c_str(),
		(int)content.size(),
		&result[0],
		size_needed
	);

	return result;
}

void FileService::WriteAllText(const std::filesystem::path& filePath, const std::wstring& content)
{
	int size_needed = WideCharToMultiByte(
		CP_UTF8,
		0,
		content.c_str(),
		(int)content.size(),
		nullptr,
		0,
		nullptr,
		nullptr
	);

	std::string utf8(size_needed, 0);

	WideCharToMultiByte(
		CP_UTF8,
		0,
		content.c_str(),
		(int)content.size(),
		&utf8[0],
		size_needed,
		nullptr,
		nullptr
	);

	std::ofstream file(filePath, std::ios::binary);
	file.write(utf8.data(), utf8.size());
}
