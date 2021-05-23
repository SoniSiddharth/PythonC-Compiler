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

IfStart0:lw $t0, 0($t8)
lw $t1, 4($t8)

ble $t0,$t1, CheckpointIfElse0
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
j ElseEnd0
CheckpointIfElse0:
lw $t0,4($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
ElseEnd0:
li $t0, 10
sw $t0,8($t8)

li $t0, 2
sw $t0,12($t8)

IfStart1:lw $t0, 12($t8)
lw $t1, 8($t8)

bge $t0,$t1, CheckpointIfElse1
lw $t0,12($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
j ElseEnd1
CheckpointIfElse1:
lw $t0,8($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
ElseEnd1:
