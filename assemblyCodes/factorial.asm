.data
main: .space 10000
.text
la $t8,main
la $t7,main
li $v0,5
syscall
move $t0,$v0
sw $t0,0($t8)

jal m_factorial
.data
factorial : .space 5000 
.text
Func_factorial:
 subu $sp,$sp,4 
 sw $ra,($sp)

la $t8,factorial
lw $t0, 0($t8)
lw $t1, 4($t8)

lw $t0, 0($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,0($t8)

li $t0, 1
sw $t0,8($t8)

li $t0, 1
sw $t0,12($t8)

li $t0, 1
sw $t0,8($t8)

ForStart0:lw $t0, 8($t8)
lw $t1, 0($t8)

bge $t0,$t1, CheckpointFor0
lw $t0, 12($t8)
lw $t1, 8($t8)
mul $t0, $t0, $t1
sw $t0,12($t8)

lw $t0, 8($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,8($t8)

j ForStart0
CheckpointFor0:

lw $v0, 12($t8)
move $t8,$t7

lw $ra,($sp)
 addu $sp,$sp,4
 jr $ra
m_factorial:
li $t0, 0
sw $t0,8($t8)

lw $t0, 0($t8)
lw $t1, 8($t8)

la $t8,factorial
sw $t0,0($t8)
sw $t1,4($t8)

jal Func_factorial
 sw $v0,12($t8)
 
.data
msg: .asciiz "\n"

.text
lw $t0,12($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
