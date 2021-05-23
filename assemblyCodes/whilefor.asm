.data
main: .space 10000
.text
la $t8,main
la $t7,main
li $t0, 0
sw $t0,0($t8)

li $t0, 0
sw $t0,4($t8)

li $t0, 4
sw $t0,8($t8)

WhileStart0:lw $t0, 4($t8)
lw $t1, 8($t8)

bge $t0,$t1, CheckpointWhile0
li $t0, 0
sw $t0,12($t8)

li $t0, 0
sw $t0,12($t8)

ForStart0:lw $t0, 12($t8)
lw $t1, 8($t8)

bge $t0,$t1, CheckpointFor0
lw $t0, 0($t8)
li $t1, 1
sub $t0, $t0, $t1
sw $t0,0($t8)

lw $t0, 12($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,12($t8)

j ForStart0
CheckpointFor0:
lw $t0, 4($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,4($t8)

j WhileStart0
CheckpointWhile0:
.data
msg: .asciiz "\n"

.text
lw $t0,0($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
