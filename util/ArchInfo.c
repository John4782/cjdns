/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "util/ArchInfo.h"

/*
Autogenerated list of arch-info, using the following:

#include "linux/elf-em.h"
#include "linux/audit.h"
#include "stdio.h"
#define EM_OPENRISC     92
static const struct { char* name; unsigned int id; } archs[] = {
    #include "arch.x"
    {0}
};
int main()
{
    int i;
    for (i=0; archs[i].name; i++) {
        printf("#define ArchInfo_%s 0x%08x\n", archs[i].name, archs[i].id);
    }
    return 0;
}

echo '#include "linux/audit.h"' | gcc -E -dM - | grep '#define AUDIT_ARCH' | \
    awk '{print "{ .name=\""$2"\", .id="$2" },"}' > arch.x

gcc arch.c
./a.out
 */
#define ArchInfo_AUDIT_ARCH_SPARC64 0x8000002b
#define ArchInfo_AUDIT_ARCH_MIPS 0x00000008
#define ArchInfo_AUDIT_ARCH_S390 0x00000016
#define ArchInfo_AUDIT_ARCH_PPC64 0x80000015
#define ArchInfo_AUDIT_ARCH_SHEL64 0xc000002a
#define ArchInfo_AUDIT_ARCH_SH 0x0000002a
#define ArchInfo_AUDIT_ARCH_PARISC64 0x8000000f
#define ArchInfo_AUDIT_ARCH_MIPSEL64 0xc0000008
#define ArchInfo_AUDIT_ARCH_IA64 0xc0000032
#define ArchInfo_AUDIT_ARCH_PARISC 0x0000000f
#define ArchInfo_AUDIT_ARCH_MIPS64 0x80000008
#define ArchInfo_AUDIT_ARCH_ALPHA 0xc0009026
#define ArchInfo_AUDIT_ARCH_MIPSEL 0x40000008
#define ArchInfo_AUDIT_ARCH_SPARC 0x00000002
#define ArchInfo_AUDIT_ARCH_I386 0x40000003
#define ArchInfo_AUDIT_ARCH_OPENRISC 0x0000005c
#define ArchInfo_AUDIT_ARCH_FRV 0x00005441
#define ArchInfo_AUDIT_ARCH_ARM 0x40000028
#define ArchInfo_AUDIT_ARCH_X86_64 0xc000003e
#define ArchInfo_AUDIT_ARCH_ARMEB 0x00000028
#define ArchInfo_AUDIT_ARCH_M68K 0x00000004
#define ArchInfo_AUDIT_ARCH_S390X 0x80000016
#define ArchInfo_AUDIT_ARCH_PPC 0x00000014
#define ArchInfo_AUDIT_ARCH_SH64 0x8000002a
#define ArchInfo_AUDIT_ARCH_SHEL 0x4000002a
#define ArchInfo_AUDIT_ARCH_M32R 0x00000058
#define ArchInfo_AUDIT_ARCH_CRIS 0x4000004c

/**
 * Manually generated detection routine...
 */
#if defined(__amd64__) || defined(__x86_64__) || defined(__AMD64__) || \
    defined(_M_X64) || defined(__amd64)
    #define ARCH ArchInfo_AUDIT_ARCH_X86_64
    #define ARCHSTR "amd64"
#elif defined(__i386__) || defined(__x86__) || defined(__X86__) || \
      defined(_M_IX86) || defined(__i386)
    #define ARCH ArchInfo_AUDIT_ARCH_I386
    #define ARCHSTR "i386"
#elif defined(__ARM_EABI__) || defined(__arm__)
    #if defined(Endian_BIG)
        #define ARCH ArchInfo_AUDIT_ARCH_ARMEB
        #define ARCHSTR "armeb"
    #elif defined(Endian_LITTLE)
        #define ARCH ArchInfo_AUDIT_ARCH_ARMEL
        #define ARCHSTR "armel"
    #else
        #error unknown endian
    #endif
#elif defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64)
    #define ARCH ArchInfo_AUDIT_ARCH_PPC64
    #define ARCHSTR "ppc64"
#elif defined(__powerpc__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
    #define ARCH ArchInfo_AUDIT_ARCH_PPC
    #define ARCHSTR "ppc"
#elif defined(__sparcv9__) || defined(__sparcv9)
    #define ARCH ArchInfo_AUDIT_ARCH_SPARC64
    #define ARCHSTR "sparc64"
    Assert_compileTime(sizeof(long) == 8);
#elif defined(__sparc_v8__)
    #define ARCH ArchInfo_AUDIT_ARCH_SPARC
    #define ARCHSTR "sparc"
    Assert_compileTime(sizeof(long) == 4);
#elif defined(__sparc__) || defined(__sparc)
    #if defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 8
        #define ARCH ArchInfo_AUDIT_ARCH_SPARC64
        #define ARCHSTR "sparc64"
    #elif defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 4
        #define ARCH ArchInfo_AUDIT_ARCH_SPARC
        #define ARCHSTR "sparc"
    #else
        #error unknown bit width
    #endif
#elif defined(__mips__) || defined(__mips) || defined(__MIPS__)
    #if defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 8
        #if defined(Endian_BIG)
            #define ARCH ArchInfo_AUDIT_ARCH_MIPS64
            #define ARCHSTR "mips64"
        #elif defined(Endian_LITTLE)
            #define ARCH ArchInfo_AUDIT_ARCH_MIPSEL64
            #define ARCHSTR "mipsel64"
        #else
            #error unknown endian
        #endif
    #elif defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 4
        #if defined(Endian_BIG)
            #define ARCH ArchInfo_AUDIT_ARCH_MIPS
            #define ARCHSTR "mips"
        #elif defined(Endian_LITTLE)
            #define ARCH ArchInfo_AUDIT_ARCH_MIPSEL
            #define ARCHSTR "mipsel"
        #else
            #error unknown endian
        #endif
    #else
        #error unknown bit width
    #endif
#else
    #error architecture unknown
#endif

uint32_t ArchInfo_getAuditArch()
{
    return ARCH;
}

char* ArchInfo_getArchStr()
{
    return ARCHSTR;
}
