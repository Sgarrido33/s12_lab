.section .text
    .global printone
    .type printone, @function

# void printone(void);
# Se asume: t0 contiene la dirección del char a imprimir
printone:
    li      a7, 64        # syscall write en RISC-V (64)
    # argumento 1: fd
    li      a0, 0         # fd = 0 (según enunciado)
    # argumento 2: pointer al buffer -> t0
    mv      a1, t0
    # argumento 3: count = 1
    li      a2, 1
    ecall
    ret