.data
main: .space 10000
.text
la $t8,main
la $t7,main
li $v0,5
syscall
move $t0,$v0
sw $t0,0($t8)

jal m_fibo
.data
fibo : .space 5000 
.text
Func_fibo:
 subu $sp,$sp,4 
 sw $ra,($sp)

la $t8,fibo
lw $t0, 0($t8)
lw $t1, 4($t8)

li $t0, 0
sw $t0,8($t8)

.data
msg: .asciiz "\n"

.text
lw $t0,8($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
li $t0, 1
sw $t0,12($t8)

lw $t0,12($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
li $t0, 1
sw $t0,4($t8)

WhileStart0:lw $t0, 4($t8)
lw $t1, 0($t8)

bge $t0,$t1, CheckpointWhile0
lw $t0, 8($t8)
sw $t0,16($t8)

lw $t0, 12($t8)
sw $t0,8($t8)

lw $t0, 16($t8)
lw $t1, 12($t8)
add $t0, $t0, $t1
sw $t0,12($t8)

lw $t0,12($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
lw $t0, 4($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,4($t8)

j WhileStart0
CheckpointWhile0:
lw $ra,($sp)
 addu $sp,$sp,4
 jr $ra
m_fibo:
li $t0, 0
sw $t0,8($t8)

lw $t0, 0($t8)
lw $t1, 8($t8)

la $t8,fibo
sw $t0,0($t8)
sw $t1,4($t8)

jal Func_fibo
 sw $v0,12($t8)
 
