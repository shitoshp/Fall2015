
###### Abiola Oke, Shitosh Parjauli #######
###### SYCS201, Project 2 #######

.data

	prompt: .asciiz "\n Please enter an integer: "
	str1: .asciiz " + "
	str2: .asciiz " - "
	str3: .asciiz "( "
	str4: .asciiz " * "
	str5: .asciiz " ) "
	str6: .asciiz "= "
	error: .asciiz "\n PLEASE MAKE SURE YOUR INTEGERS ARE BETWEEN 0 AND 32768, IF NOT YOU WILL ENTER ALL INTEGERS AGAIN."
	#str5: .asciiz "A + B - (C - D * E) = X"
	.align 3
	array: .space 20          		 #assign 20 spaces for prompting 5 integers

.text

main:

ERROR:

#####Print error message, start again########
	la $a0, error
	li $v0, 4
	syscall

li $t0, 0    						 #initialize t0 to 0


LOOP:

	la $a0, prompt                   #printing the prompt
	li $v0, 4
	syscall

	li $v0, 5
	syscall                          #reading integer from user to v0

###### Checking if integer is in correct range #########
	slt $t3, $0, $v0
	beq $t3, $0, ERROR
	slt $t3, $v0, 32768
	beq $t3, $0, ERROR

	sw $v0, array($t0)				 #storing v0 to beginning of array since t0 is 0

	addi $t0, $t0, 4                 #increasing t0 so we can save next value at next location in array
	slt $t1, $t0, 20					 #if $t0 < 20
	bne $t1, $zero, LOOP             #go to LOOP
	j DONE
DONE:


la $s5, array 						 #loading the array to a register
lw $t0, 0($s5)						 #loading individual elements from array to registers
lw $t1, 4($s5)
lw $t2, 8($s5)
lw $t3, 12($s5)
lw $t4, 16($s5)

############ Printing A + B - (C - D * E) = ################

li $v0, 1
la $a0, ($t0)
syscall

li $v0, 4
la $a0, str1
syscall

li $v0, 1
la $a0, ($t1)
syscall

li $v0, 4
la $a0, str2
syscall

li $v0, 4
la $a0, str3
syscall

li $v0, 1
la $a0, ($t2)
syscall

li $v0, 4
la $a0, str2
syscall

li $v0, 1
la $a0, ($t3)
syscall

li $v0, 4
la $a0, str4
syscall

li $v0, 1
la $a0, ($t4)
syscall

li $v0, 4
la $a0, str5
syscall

li $v0, 4
la $a0, str6
syscall

########## Performing Calculations  ###########

mult $t3, $t4
mflo $t3
sub $t2, $t2, $t3
sub $t1, $t1, $t2
add $t0, $t0, $t1

########## Printing Answer ##########

li $v0, 1
la $a0, ($t0)
syscall


jr $ra



