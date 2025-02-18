#include <sstream>

#include "build_info.h"

namespace bpftrace {

std::string BuildInfo::report()
{
  std::stringstream buf;

  buf << "Build" << std::endl
      << "  version: " << BPFTRACE_VERSION << std::endl
      << "  LLVM: " << LLVM_VERSION_MAJOR << "." << LLVM_VERSION_MINOR << "."
      << LLVM_VERSION_PATCH << std::endl
      << "  foreach_sym: "
#ifdef HAVE_BCC_ELF_FOREACH_SYM
      << "yes" << std::endl
#else
      << "no" << std::endl
#endif
      << "  unsafe uprobe: "
#ifdef HAVE_UNSAFE_UPROBE
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  bfd: "
#ifdef HAVE_BFD_DISASM
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  bcc_usdt_addsem: "
#ifdef HAVE_BCC_USDT_ADDSEM
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  bcc bpf_attach_uprobe refcount: "
#ifdef LIBBCC_ATTACH_UPROBE_SEVEN_ARGS_SIGNATURE
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  bcc library path resolution: "
#ifdef HAVE_BCC_WHICH_SO
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  libbpf btf dump: "
#ifdef HAVE_LIBBPF_BTF_DUMP
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  libbpf btf dump type decl: "
#ifdef HAVE_LIBBPF_BTF_DUMP_EMIT_TYPE_DECL
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  libbpf bpf_prog_load: "
#ifdef HAVE_LIBBPF_BPF_PROG_LOAD
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  libbpf bpf_map_create: "
#ifdef HAVE_LIBBPF_BPF_MAP_CREATE
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif
  buf << "  libdw (DWARF support): "
#ifdef HAVE_LIBDW
      << "yes" << std::endl;
#else
      << "no" << std::endl;
#endif

  return buf.str();
}

} // namespace bpftrace
