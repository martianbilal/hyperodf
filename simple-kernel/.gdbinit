b dump_cpu_state
b stupid_stub_function

print "loaded the init file"
r

print "Pre fork CPU states"
print "==========Pre fork CPUstate=========="
p *cpu
print "==========Pre fork X86_CPU=========="
p *X86_CPU(cpu)
p *KVM_STATE(current_accel())
p *(X86_CPU(cpu)->kvm_msr_buf)
print "==========Pre fork end=========="
c 

print "Post fork CPU states"
print "==========Post fork CPUstate=========="
p *cpu
print "==========Post fork X86_CPU=========="
p *X86_CPU(cpu)
p *KVM_STATE(current_accel())
p *(X86_CPU(cpu)->kvm_msr_buf)
print "==========Post fork end=========="



quit