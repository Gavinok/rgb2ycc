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
	.file	"Read_PPM.c"
	.text
	.align	2
	.global	applyModifierPPM
	.type	applyModifierPPM, %function
applyModifierPPM:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 112
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	subs	r9, r0, #0
	sub	sp, sp, #116
	beq	.L12
	ldr	r1, [r9, #0]
	mov	r3, #0
	ldr	r2, [r9, #4]
	str	r1, [sp, #4]
	mov	r1, r1, asl #1
	str	r1, [sp, #20]
	add	r1, r3, #2
	cmp	r2, r1
	str	r2, [sp, #8]
	str	r3, [sp, #12]
	str	r1, [sp, #16]
	ble	.L14
.L9:
	ldr	r2, [sp, #12]
	ldr	r3, [sp, #4]
	add	sl, r2, #2
	add	fp, r2, r3
	cmp	fp, sl
	movle	sl, r2
	movle	r8, sl
	ble	.L5
	mov	ip, r2
	b	.L7
.L15:
	mov	sl, r3
.L7:
	ldr	r1, [sp, #4]
	add	r2, ip, r1
	add	r0, r2, #1
	add	r1, ip, #1
	ldr	r3, [r9, #8]
	mov	r4, ip, asl #1
	mov	r5, r1, asl #1
	mov	r6, r2, asl #1
	mov	r7, r0, asl #1
	add	r5, r5, r1
	add	r7, r7, r0
	add	r4, r4, ip
	add	r6, r6, r2
	add	ip, r3, r5
	add	r2, r3, r4
	add	r8, r3, r7
	add	r0, sp, #106
	add	r3, r3, r6
	add	r1, sp, #76
	str	ip, [sp, #80]
	str	r3, [sp, #84]
	str	r2, [sp, #76]
	str	r8, [sp, #88]
	bl	rgb_to_ycbcr2
	add	r1, sp, #94
	add	r0, sp, #106
	bl	ycbcr_to_rgb2
	ldr	r0, [r9, #8]
	add	r1, sp, #94
	mov	r2, #3
	add	r0, r0, r4
	bl	memcpy
	ldr	r0, [r9, #8]
	add	r1, sp, #97
	mov	r2, #3
	add	r0, r0, r5
	bl	memcpy
	ldr	r0, [r9, #8]
	add	r1, sp, #100
	mov	r2, #3
	add	r0, r0, r6
	bl	memcpy
	ldr	r0, [r9, #8]
	add	r1, sp, #103
	add	r0, r0, r7
	mov	r2, #3
	bl	memcpy
	add	r3, sl, #2
	cmp	r3, fp
	mov	ip, sl
	blt	.L15
	mov	r8, sl
.L5:
	add	r3, sl, #1
	cmp	r3, fp
	blt	.L16
.L8:
	ldr	r1, [sp, #12]
	ldr	r2, [sp, #20]
	ldr	r3, [sp, #16]
	add	r1, r1, r2
	ldr	r2, [sp, #8]
	str	r1, [sp, #12]
	add	r1, r3, #2
	cmp	r2, r1
	str	r1, [sp, #16]
	bgt	.L9
.L14:
	cmp	r2, r3
	ble	.L12
	ldr	r2, [sp, #4]
	mul	r2, r3, r2
	ldr	r3, [sp, #4]
	add	r6, r2, #2
	add	r7, r2, r3
	cmp	r6, r7
	bge	.L10
	mov	r1, r2
	add	fp, sp, #106
	add	sl, sp, #94
.L11:
	add	r2, r1, #1
	ldr	r3, [r9, #8]
	mov	r4, r1, asl #1
	mov	r5, r2, asl #1
	add	r4, r4, r1
	add	r5, r5, r2
	add	r2, r3, r5
	mov	r0, fp
	add	r3, r3, r4
	add	r1, sp, #44
	str	r3, [sp, #52]
	str	r3, [sp, #44]
	str	r2, [sp, #56]
	str	r2, [sp, #48]
	bl	rgb_to_ycbcr2
	mov	r1, sl
	mov	r0, fp
	bl	ycbcr_to_rgb2
	ldr	r0, [r9, #8]
	mov	r1, sl
	mov	r2, #3
	add	r0, r0, r4
	bl	memcpy
	ldr	r0, [r9, #8]
	add	r1, sp, #97
	add	r0, r0, r5
	mov	r2, #3
	bl	memcpy
	add	r3, r6, #2
	cmp	r3, r7
	mov	r1, r6
	mov	r6, r3
	blt	.L11
.L10:
	add	r3, r8, #1
	cmp	r3, r7
	blt	.L17
.L12:
	add	sp, sp, #116
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
.L16:
	ldr	r3, [sp, #4]
	add	r2, sl, r3
	mov	r5, r2, asl #1
	ldr	r3, [r9, #8]
	mov	r4, sl, asl #1
	add	r5, r5, r2
	add	r4, r4, sl
	add	r2, r3, r5
	add	r0, sp, #106
	add	r3, r3, r4
	add	r1, sp, #60
	str	r3, [sp, #64]
	str	r2, [sp, #72]
	str	r3, [sp, #60]
	str	r2, [sp, #68]
	bl	rgb_to_ycbcr2
	add	r1, sp, #94
	add	r0, sp, #106
	bl	ycbcr_to_rgb2
	ldr	r0, [r9, #8]
	add	r1, sp, #94
	add	r0, r0, r4
	mov	r2, #3
	bl	memcpy
	ldr	r0, [r9, #8]
	add	r1, sp, #100
	add	r0, r0, r5
	mov	r2, #3
	bl	memcpy
	b	.L8
.L17:
	ldr	r3, [r9, #8]
	mov	r4, r8, asl #1
	add	r4, r4, r8
	add	r5, sp, #106
	add	r3, r3, r4
	mov	r0, r5
	add	r1, sp, #28
	add	r6, sp, #94
	str	r3, [sp, #40]
	str	r3, [sp, #28]
	str	r3, [sp, #32]
	str	r3, [sp, #36]
	bl	rgb_to_ycbcr2
	mov	r1, r6
	mov	r0, r5
	bl	ycbcr_to_rgb2
	ldr	r0, [r9, #8]
	mov	r1, r6
	add	r0, r0, r4
	mov	r2, #3
	bl	memcpy
	b	.L12
	.size	applyModifierPPM, .-applyModifierPPM
	.align	2
	.global	writePPM
	.type	writePPM, %function
writePPM:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, lr}
	mov	r4, r1
	ldr	r1, .L22
	mov	r6, r0
	bl	fopen
	subs	r5, r0, #0
	beq	.L21
	mov	r3, r5
	mov	r1, #1
	mov	r2, #3
	ldr	r0, .L22+4
	bl	fwrite
	mov	r0, r5
	ldr	r1, .L22+8
	ldr	r2, .L22+12
	bl	fprintf
	ldmia	r4, {r2, r3}	@ phole ldm
	mov	r0, r5
	ldr	r1, .L22+16
	bl	fprintf
	mov	r0, r5
	ldr	r1, .L22+20
	mov	r2, #255
	bl	fprintf
	ldr	r3, [r4, #0]
	mov	r1, r3, asl #1
	add	r1, r1, r3
	ldr	r2, [r4, #4]
	mov	r3, r5
	ldr	r0, [r4, #8]
	bl	fwrite
	ldr	r0, [r4, #8]
	bl	free
	mov	r0, r4
	bl	free
	mov	r0, r5
	bl	fclose
	ldmfd	sp!, {r4, r5, r6, lr}
	bx	lr
.L21:
	ldr	r3, .L22+24
	mov	r2, r6
	ldr	r0, [r3, #0]
	ldr	r1, .L22+28
	bl	fprintf
	mov	r0, #1
	bl	exit
.L23:
	.align	2
.L22:
	.word	.LC0
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	stderr
	.word	.LC1
	.size	writePPM, .-writePPM
	.align	2
	.global	readPPM
	.type	readPPM, %function
readPPM:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, lr}
	ldr	r1, .L49
	sub	sp, sp, #28
	mov	r7, r0
	bl	fopen
	subs	r4, r0, #0
	beq	.L42
	add	r0, sp, #4
	mov	r1, #16
	mov	r2, r4
	bl	fgets
	cmp	r0, #0
	beq	.L43
	ldrb	r3, [sp, #4]	@ zero_extendqisi2
	cmp	r3, #80
	bne	.L27
	ldrb	r3, [sp, #5]	@ zero_extendqisi2
	cmp	r3, #54
	beq	.L28
.L27:
	ldr	r2, .L49+4
	ldr	r0, .L49+8
	ldr	r3, [r2, #0]
	mov	r1, #1
	mov	r2, #36
	bl	fwrite
	mov	r0, #1
	bl	exit
.L28:
	mov	r0, #12
	bl	malloc
	subs	r5, r0, #0
	beq	.L44
	mov	r0, r4
	bl	_IO_getc
	and	r0, r0, #255
	cmp	r0, #35
	bne	.L30
.L41:
	mov	r0, r4
	bl	_IO_getc
	cmp	r0, #10
	bne	.L41
	mov	r0, r4
	bl	_IO_getc
	and	r0, r0, #255
	cmp	r0, #35
	beq	.L41
.L30:
	mov	r1, r4
	bl	ungetc
	mov	r0, r4
	ldr	r1, .L49+12
	mov	r2, r5
	add	r3, r5, #4
	bl	__isoc99_fscanf
	cmp	r0, #2
	bne	.L45
	mov	r0, r4
	ldr	r1, .L49+16
	add	r2, sp, #20
	bl	__isoc99_fscanf
	cmp	r0, #1
	mov	r6, r0
	bne	.L46
	ldr	r3, [sp, #20]
	cmp	r3, #255
	bne	.L47
.L38:
	mov	r0, r4
	bl	fgetc
	cmp	r0, #10
	bne	.L38
	ldr	r1, [r5, #4]
	ldr	r3, [r5, #0]
	mul	r2, r3, r1
	mov	r0, r2, asl #1
	add	r0, r0, r2
	bl	malloc
	ldr	r3, [r5, #0]
	mov	r1, r3, asl #1
	add	r1, r1, r3
	str	r0, [r5, #8]
	mov	r3, r4
	ldr	r2, [r5, #4]
	bl	fread
	ldr	r3, [r5, #4]
	cmp	r0, r3
	bne	.L48
	mov	r0, r4
	bl	fclose
	mov	r0, r5
	add	sp, sp, #28
	ldmfd	sp!, {r4, r5, r6, r7, lr}
	bx	lr
.L42:
	ldr	r3, .L49+4
	mov	r2, r7
	ldr	r0, [r3, #0]
	ldr	r1, .L49+20
	bl	fprintf
	mov	r0, #1
	bl	exit
.L43:
	mov	r0, r7
	bl	perror
	mov	r0, #1
	bl	exit
.L44:
	ldr	r2, .L49+4
	ldr	r0, .L49+24
	ldr	r3, [r2, #0]
	mov	r1, #1
	mov	r2, #26
	bl	fwrite
	mov	r0, #1
	bl	exit
.L48:
	ldr	r3, .L49+4
	mov	r2, r7
	ldr	r0, [r3, #0]
	ldr	r1, .L49+28
	bl	fprintf
	mov	r0, #1
	bl	exit
.L47:
	ldr	r3, .L49+4
	mov	r2, r7
	ldr	r0, [r3, #0]
	ldr	r1, .L49+32
	bl	fprintf
	mov	r0, r6
	bl	exit
.L46:
	ldr	r3, .L49+4
	mov	r2, r7
	ldr	r0, [r3, #0]
	ldr	r1, .L49+36
	bl	fprintf
	mov	r0, #1
	bl	exit
.L45:
	ldr	r3, .L49+4
	mov	r2, r7
	ldr	r0, [r3, #0]
	ldr	r1, .L49+40
	bl	fprintf
	mov	r0, #1
	bl	exit
.L50:
	.align	2
.L49:
	.word	.LC7
	.word	stderr
	.word	.LC8
	.word	.LC10
	.word	.LC12
	.word	.LC1
	.word	.LC9
	.word	.LC15
	.word	.LC14
	.word	.LC13
	.word	.LC11
	.size	readPPM, .-readPPM
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"wb\000"
	.space	1
.LC1:
	.ascii	"Unable to open file '%s'\012\000"
	.space	2
.LC2:
	.ascii	"P6\012\000"
.LC3:
	.ascii	"# Created by %s\012\000"
	.space	3
.LC4:
	.ascii	"bmazerolle\000"
	.space	1
.LC5:
	.ascii	"%d %d\012\000"
	.space	1
.LC6:
	.ascii	"%d\012\000"
.LC7:
	.ascii	"rb\000"
	.space	1
.LC8:
	.ascii	"Invalid image format (must be 'P6')\012\000"
	.space	3
.LC9:
	.ascii	"Unable to allocate memory\012\000"
	.space	1
.LC10:
	.ascii	"%d %d\000"
	.space	2
.LC11:
	.ascii	"Invalid image size (error loading '%s')\012\000"
	.space	3
.LC12:
	.ascii	"%d\000"
	.space	1
.LC13:
	.ascii	"Invalid rgb component (error loading '%s')\012\000"
.LC14:
	.ascii	"'%s' does not have 8-bits components\012\000"
	.space	2
.LC15:
	.ascii	"Error loading image '%s'\012\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
