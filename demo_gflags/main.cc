#include <gflags/gflags.h>
#include <iostream>

static bool ValidatePort(const char *flagname, int32_t value)
{
  if (value > 0 && value < 32768) // value is ok
    return true;
  printf("Invalid value for --%s: %d\n", flagname, (int)value);
  return false;
}

DEFINE_bool(big_menu,
            true,
            "Include 'advance' option in the menu listing");
DEFINE_string(languages,
              "english, french, chinese",
              "comma-separated list of languages to offer in the 'lang' menu");
DEFINE_uint32(age,
              10,
              "age");

DEFINE_int32(port,
             0,
             "What port to listen on");
static const bool port_dummy = gflags::RegisterFlagValidator(&FLAGS_port, &ValidatePort);

int main(int argc, char **argv)
{
  std::cout << std::boolalpha; // 为了让bool类型输出true/false，而不是 1/0
  std::cout << "big_menu: " << FLAGS_big_menu << '\n'
            << "languages: " << FLAGS_languages << '\n'
            << "age: " << FLAGS_age << std::endl;

  return 0;
}
