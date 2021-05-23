.data
main: .space 10000
.text
la $t8,main
la $t7,main
li $v0,5
syscall
move $t0,$v0
sw $t0,0($t8)

li $v0,5
syscall
move $t0,$v0
sw $t0,4($t8)

jal m_sum
.data
sum : .space 5000 
.text
Func_sum:
 subu $sp,$sp,4 
 sw $ra,($sp)

la $t8,sum
lw $t0, 0($t8)
lw $t1, 4($t8)

lw $t0, 0($t8)
lw $t1, 4($t8)
add $t0, $t0, $t1
sw $t0,8($t8)


lw $v0, 8($t8)
move $t8,$t7

lw $ra,($sp)
 addu $sp,$sp,4
 jr $ra
m_sum:
jal m_mult
.data
mult : .space 5000 
.text
Func_mult:
 subu $sp,$sp,4 
 sw $ra,($sp)

la $t8,mult
lw $t0, 0($t8)
lw $t1, 4($t8)

lw $t0, 0($t8)
lw $t1, 4($t8)

la $t8,sum
sw $t0,0($t8)
sw $t1,4($t8)

jal Func_sum
 sw $v0,8($t8)
 
lw $t0, 8($t8)
lw $t1, 4($t8)
mul $t0, $t0, $t1
sw $t0,8($t8)


lw $v0, 8($t8)
move $t8,$t7

lw $ra,($sp)
 addu $sp,$sp,4
 jr $ra
m_mult:
lw $t0, 0($t8)
lw $t1, 4($t8)

la $t8,mult
sw $t0,0($t8)
sw $t1,4($t8)

jal Func_mult
 sw $v0,16($t8)
 
.data
msg: .asciiz "\n"

.text
lw $t0,16($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
