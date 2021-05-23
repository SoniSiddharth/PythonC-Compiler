.data
main: .space 10000
.text
la $t8,main
la $t7,main
.data
arr : .space 20 
.text

.data
brr : .space 20 
.text

.data
crr : .space 20 
.text

li $t0, 0
sw $t0,12($t8)

li $t0, 5
sw $t0,16($t8)

li $t0, 0
sw $t0,12($t8)

ForStart0:lw $t0, 12($t8)
lw $t1, 16($t8)

bge $t0,$t1, CheckpointFor0
lw $t0, 12($t8)
move $s1,$t0
lw $t0,12($t8)
li $t3,4
mul $t0,$t0,$t3
sw $s1,arr($t0)

lw $t0, 12($t8)
li $t1, 1
add $t0, $t0, $t1
move $s1,$t0
lw $t0,12($t8)
li $t3,4
mul $t0,$t0,$t3
sw $s1,brr($t0)

lw $t0, 12($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,12($t8)

j ForStart0
CheckpointFor0:
li $t0, 0
sw $t0,20($t8)

li $t0, 0
sw $t0,20($t8)

ForStart1:lw $t0, 20($t8)
lw $t1, 16($t8)

bge $t0,$t1, CheckpointFor1
lw $t0, 20($t8)
li $t3,4
mul $t0,$t0,$t3
lw $t0,arr($t0)

sw $t0,24($t8)

lw $t1, 20($t8)
li $t3,4
mul $t0,$t0,$t3
lw $t0,brr($t0)

sw $t0,28($t8)

lw $t0, 24($t8)
lw $t1, 28($t8)
add $t0, $t0, $t1
move $s1,$t0
lw $t0,20($t8)
li $t3,4
mul $t0,$t0,$t3
sw $s1,crr($t0)

lw $t0, 20($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,20($t8)

j ForStart1
CheckpointFor1:
li $t0, 0
sw $t0,32($t8)

li $t0, 0
sw $t0,32($t8)

ForStart2:lw $t0, 32($t8)
lw $t1, 16($t8)

bge $t0,$t1, CheckpointFor2
lw $t0, 32($t8)
li $t3,4
mul $t0,$t0,$t3
lw $t0,crr($t0)

sw $t0,36($t8)

.data
msg: .asciiz "\n"

.text
lw $t0,36($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
lw $t0, 32($t8)
li $t1, 1
add $t0, $t0, $t1
sw $t0,32($t8)

j ForStart2
CheckpointFor2:
