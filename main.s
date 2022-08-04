	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	ldr	r0, .L3
	bl	readPPM
	mov	r4, r0
	bl	applyModifierPPM
	mov	r1, r4
	ldr	r0, .L3+4
	bl	writePPM
	mov	r0, #0
	ldmfd	sp!, {r4, lr}
	bx	lr
.L4:
	.align	2
.L3:
	.word	.LC0
	.word	.LC1
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"img_forest.ppm\000"
	.space	1
.LC1:
	.ascii	"img_forest2.ppm\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
