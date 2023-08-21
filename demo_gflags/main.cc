#include <gflags/gflags.h>
#include <iostream>

// 标志验证器
static bool ValidatePort(const char *flagname, int32_t value)
{
  if (value > 0 && value < 32768) // value is ok
    return true;
  printf("Invalid value for --%s: %d\n", flagname, (int)value);
  return false;
}

// 标志定义
DEFINE_bool(big_menu, true, "Include 'advance' option in the menu listing");
DEFINE_string(languages, "english, french, chinese", "comma-separated list of languages to offer in the 'lang' menu");
DEFINE_int32(port, 9988, "What port to listen on");

// 注册标志验证器
static const bool port_dummy = gflags::RegisterFlagValidator(&FLAGS_port, &ValidatePort);

int main(int argc, char **argv)
{
  // 设置版本
  gflags::SetVersionString("1.1.0");
  // 设置使用帮助信息
  gflags::SetUsageMessage("./main --big_menu --languages=\"english, french, chinese\" --port=9988");
  // 命令行参数解析
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout << std::boolalpha; // 为了让bool类型输出true/false，而不是 1/0
  std::cout << "big_menu: " << FLAGS_big_menu << '\n'
            << "languages: " << FLAGS_languages << '\n'
            << "port: " << FLAGS_port << std::endl;

  return 0;
}
