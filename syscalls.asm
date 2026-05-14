DEFAULT REL


section .data
    __NtAllocateVirtualMemoryEx dd 0x0078
    __NtWriteVirtualMemory dd 0x003a
    __NtCreateThreadEx dd 0x00c9
    __NtWaitForSingleObject dd 0x0004


section .text
global alloc_mem_ex
global wr_mem
global cr_thread
global wait_single_obj

alloc_mem_ex:
    mov r10, rcx
    mov eax, [__NtAllocateVirtualMemoryEx] 
    syscall
    ret

wr_mem:
    mov r10, rcx
    mov eax, [__NtWriteVirtualMemory]
    syscall
    ret

cr_thread:
    mov r10, rcx
    mov eax, [__NtCreateThreadEx]
    syscall
    ret

wait_single_obj:
    mov r10, rcx
    mov eax, [__NtWaitForSingleObject]
    syscall
    ret