.data

	prompt: .asciiz "\n Please enter an integer: "
	errorm: .asciiz "\n PLEASE MAKE SURE YOUR INTEGERS ARE BETWEEN 0 AND 32768, IF NOT YOU WILL ENTER ALL INTEGERS AGAIN."
	str1: .asciiz " "
	str2: .asciiz "\n The hexadecimal value for "
	str3: .asciiz " is "
	#str5: .asciiz "A + B - (C - D * E) = X"
	.align 3
	array: .space 20          		 #assign 20 spaces for prompting 5 integers
	hexvalue: .space 4
.text

main:

ERROR:

la $a0, errorm
li $v0, 4
syscall
li $t0, 0

LOOP:


	la $a0, prompt                   #printing the prompt
	li $v0, 4
	syscall

	li $v0, 5
	syscall                          #reading integer from user to v0
	


	sw $v0, array($t0)				 #storing v0 to beginning of array since t0 is 0

	addi $t0, $t0, 4                 #increasing t0 so we can save next value at next location in array
	slt $t1, $t0, 20					 #if $t0 < 20
	bne $t1, $zero, LOOP             #go to LOOP
	j DONE

DONE:

li $t5, 0 
li $t3, 0						 #loading the array to a register

LOOP1:
	#addi $t5, $zero, 0
	
	lw $t0, array($t5)						 #load first element of array to t0

	# li $v0, 1
	# la $a0, ($t0)
	# syscall

	li $v0, 4 								#printing space
	la $a0, str1
	syscall

	slt $t1, $0, $t0						#checking if number is in range
	beq $t1, $0, ERROR
	slt $t1, $t0, 32768
	beq $t1, $0, ERROR



	addi $t3, $t3, 4 						#incrementing counters
	addi $t5, $t5, 4

	####test#####
	

	slt $t2, $t3, 20
	bne $t2, $zero, LOOP1



	j DONE1
DONE1:

addi $t9, $zero, 0 							#set 2 counters to 0
li $t7, 0


HEXLOOP:
	
	lw $a1, array($t9) 						#load the first element of the array to a register a1 so the argument can be passed to subprogram

	li $v0, 4 								#printing "The hex value for ___ is"
	la $a0, str2
	syscall

	li $v0, 1   ##new##
	la $a0, ($a1)
	syscall

	li $v0, 4
	la $a0, str3
	syscall

	jal subp 								#calling subprogram

	li $v0, 4 								#putting the value returned by subprogram into $a0 for printing the converted value
	addi $a0, $v1, 0
	syscall

	
	addi $t9, $t9, 4 						#shifting array by 4 bytes to get next int for next conversion

	li $v0, 4
	la $a0, str1
	syscall

	addi $t7, $t7, 1
	slt $t2, $t7, 5
	bne $t2, $zero, HEXLOOP



	j FINISH

# lw $a1, array($t9)

# jal subp

# li $v0, 4
# addi $a0, $v1, 0
# syscall

FINISH:
	li $v0, 10 								#Exiting program
	syscall

subp: 										#subprogram
	

	addi $t0, $a1, 0 						#putting the argument received from main to a temporary register
	li $t5, 4 								#setting a counter for loop
	la $t6, hexvalue						#in a register, loading the address of array called hexvalue

	Loop:

		beqz $t5, Exit
		andi $t1, $t0, 0xf 					#logical and of parameter with 15 (0xf in hexadecimal)
		slt $t2, $t1, 10 					#go to add if less than 10
		bne $t2, $zero, ADD
		addi $t1, $t1, -10 					#else, subtract 10 and add to ascii value of A
		addi $t1, $t1, 65 		
		j END



		ADD:
			addi $t1, $t1, 48 				#add to ascii value of 0

	END:
		# la $a0, ($t1)
		# li $v0, 1
		# syscall
		
		srl $t0, $t0, 4 					#shift parameter by 4 bits
		sb $t1, 3($t6) 						#store the ascii byte to the address of $t6 (hexvalue array)
		
		# la $a0, ($t1)
		# li $v0, 1
		# syscall
		
		addi $t6, $t6, -1 					#moving the memory address by -1 to put another byte in front the last number
		addi $t5, $t5, -1

	j Loop

	Exit:
		la $v1, hexvalue					#at v1, load hexvalue


		jr $ra 								#jump back register



	