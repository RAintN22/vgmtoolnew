#pragma once

// General purpose functions, not specific to anything much
// except most are VGM-centric

#include <string>

class IVGMToolCallback;

bool file_exists(const std::string& filename, const IVGMToolCallback& callback);

bool decompress(char* filename, const IVGMToolCallback& callback);

bool compress(const std::string& filename, const IVGMToolCallback& callback);

void change_ext(char* filename, const char* ext);

std::string make_temp_filename(const std::string& src);
char* make_suffixed_filename(const char* src, const char* suffix, const IVGMToolCallback& callback);

void replace_file(const char* filetoreplace, const char* with);

#define ROUND(x) ((int)(x>0?x+0.5:x-0.5))

class Utils
{
public:
#if defined(__RESHARPER__) || defined(__GNUC__)
    [[gnu::format(printf, 1, 2)]]
#endif
    static std::string format(const char* format, ...);

    static bool file_exists(const std::string& filename);
    static int file_size(const std::string& filename);
    static void compress(const std::string& filename, int iterations = -1);

    static int make_word(int b1, int b2);
};
