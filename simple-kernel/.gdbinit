
set detach-on-fork off
set follow-fork-mode child

b dump_cpu_state
b stupid_stub_function

print "loaded the init file"
r

print "Post fork CPU states"
print "==========Post fork CPUstate=========="
p *cpu
print "==========Post fork X86_CPU=========="
p *X86_CPU(cpu)
# print "==========Post fork CPU_ENV=========="
# p X86_CPU(cpu)->env
print "==========Post fork CPU_ENV->XSAVE_BUF=========="
p (X86XSaveArea)(X86_CPU(cpu)->env->xsave_buf)
print "==========Post fork KVM STATE=========="
p *KVM_STATE(current_accel())
p *(X86_CPU(cpu)->kvm_msr_buf)
print "==========Post fork X86_CPU(cpu)->kvm_msr_buf->entries=========="
p *(X86_CPU(cpu)->kvm_msr_buf->entries)@(X86_CPU(cpu)->kvm_msr_buf->nmsrs)
print "==========Post fork CPU->KVM_RUN=========="
p *cpu->kvm_run
print "==========Post fork end=========="

#continue to the end of the child process
c

# Go back to the parent 
inferior 1

#continue to the dump_cpu_state
c

print "Pre fork CPU states"
print "==========Pre fork CPUstate=========="
p *cpu
print "==========Pre fork X86_CPU=========="
p *X86_CPU(cpu)
# print "==========Pre fork CPU_ENV=========="
# p X86_CPU(cpu)->env
print "==========Pre fork CPU_ENV->XSAVE_BUF=========="
p (X86XSaveArea)(X86_CPU(cpu)->env->xsave_buf)
print "==========Pre fork KVM STATE=========="
p *KVM_STATE(current_accel())
p *(X86_CPU(cpu)->kvm_msr_buf)
print "==========Pre fork X86_CPU(cpu)->kvm_msr_buf->entries=========="
p *(X86_CPU(cpu)->kvm_msr_buf->entries)@(X86_CPU(cpu)->kvm_msr_buf->nmsrs)
print "==========Pre fork CPU->KVM_RUN=========="
p *cpu->kvm_run
print "==========Pre fork end=========="



quit