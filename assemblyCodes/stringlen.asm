.data
main: .space 10000
.text
la $t8,main
la $t7,main
.data
c: .asciiz "aeiou"
.text

.data
msg: .asciiz "\n"

.text
li $v0,4
la $a0,c
syscall

li $v0,4
la $a0,msg
syscall

la $s0,c
lb $s1,($s0)
li $t0,0
srchlp_0: beq $s1, $zero, srchdn_0 
addi $t0,$t0,1
addi $s0,$s0,1
lb $s1,($s0)
b srchlp_0
srchdn_0: sw $t0,4($t8)
lw $t0,4($t8)
li $v0,1
move $a0,$t0
syscall

li $v0,4
la $a0,msg
syscall
