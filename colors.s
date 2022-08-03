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
	.file	"colors.c"
	.text
	.align	2
	.global	add
	.type	add, %function
add:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	add	r0, r1, r0
	bx	lr
	.size	add, .-add
	.align	2
	.global	rgb_to_ycbcr
	.type	rgb_to_ycbcr, %function
rgb_to_ycbcr:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	sub	sp, sp, #56
	str	r0, [sp, #44]
	ldrb	fp, [sp, #45]	@ zero_extendqisi2
	ldrb	r0, [sp, #44]	@ zero_extendqisi2
	ldrb	r9, [sp, #46]	@ zero_extendqisi2
	mov	r7, fp, asl #5
	mov	r4, fp, asl #7
	rsb	r4, r7, r4
	mov	r5, r9, asl #6
	mov	r3, r0, asl #5
	add	r4, r4, fp
	mov	r8, r9, asl #3
	mov	r2, r0, asl #2
	mov	r1, fp, asl #3
	str	r1, [sp, #40]
	str	r5, [sp, #36]
	rsb	r6, r8, r5
	add	r2, r2, r3
	mov	r5, r4, asl #2
	mov	r3, r0, asl #6
	sub	r3, r3, r0, asl #3
	add	r2, r2, r0
	ldr	sl, [sp, #40]
	rsb	r5, r4, r5
	ldr	r4, [sp, #40]
	ldr	r1, .L5
	rsb	r3, r0, r3
	mov	ip, fp, asl #9
	mov	r2, r2, asl #2
	rsb	ip, r4, ip
	rsb	r7, sl, r7
	mov	r4, r0, asl #8
	rsb	r2, r2, #0
	mov	r3, r3, asl #3
	add	r4, r4, r0
	rsb	r3, r0, r3
	rsb	r7, fp, r7
	smull	r0, fp, r1, r2
	str	r4, [sp, #8]
	str	fp, [sp, #4]
	smull	fp, r4, r1, r5
	str	r4, [sp, #28]
	smull	r4, r0, r1, ip
	mov	sl, r9, asl #4
	sub	sl, sl, r9, asl #1
	ldr	fp, [sp, #8]
	str	r0, [sp, #20]
	mov	r0, sl, asl #3
	rsb	r0, sl, r0
	smull	r4, sl, r1, fp
	str	sl, [sp, #24]
	smull	fp, sl, r1, r3
	mov	r7, r7, asl #4
	str	sl, [sp, #12]
	smull	sl, r4, r1, r7
	ldr	fp, [sp, #36]
	rsb	r6, r9, r6
	add	r8, r8, fp
	mov	r6, r6, asl #3
	rsb	r8, r9, r8
	rsb	r6, r9, r6
	str	r4, [sp, #8]
	smull	r9, r4, r1, r0
	str	r4, [sp, #16]
	smull	r4, fp, r1, r8
	smull	sl, r9, r1, r6
	str	fp, [sp, #32]
	ldr	sl, [sp, #4]
	ldr	fp, [sp, #28]
	ldr	r1, [sp, #20]
	mov	r2, r2, asr #31
	mov	r5, r5, asr #31
	sub	r5, r5, fp, asr #6
	ldr	r4, [sp, #12]
	rsb	r2, r2, sl, asr #6
	ldr	fp, [sp, #24]
	ldr	sl, [sp, #8]
	mov	ip, ip, asr #31
	rsb	ip, ip, r1, asr #6
	mov	r3, r3, asr #31
	ldr	r1, [sp, #16]
	mov	r7, r7, asr #31
	rsb	r3, r3, r4, asr #6
	sub	r7, r7, sl, asr #6
	add	r2, r2, r5
	add	ip, ip, fp, lsr #6
	ldr	r4, [sp, #32]
	mov	r6, r6, asr #31
	mov	r0, r0, asr #31
	rsb	r0, r0, r1, asr #6
	add	r3, r3, r7
	rsb	r6, r6, r9, asr #6
	mov	r8, r8, asr #31
	sub	r2, r2, #128
	add	ip, ip, #16
	add	r2, r2, r6
	add	ip, ip, r0
	sub	r8, r8, r4, asr #6
	sub	r3, r3, #128
	add	r3, r3, r8
	strb	r2, [sp, #54]
	strb	ip, [sp, #53]
	strb	r3, [sp, #55]
	ldrb	r0, [sp, #53]	@ zero_extendqisi2
	ldrb	r3, [sp, #54]	@ zero_extendqisi2
	ldrb	r2, [sp, #55]	@ zero_extendqisi2
	orr	r0, r0, r3, asl #8
	orr	r0, r0, r2, asl #16
	add	sp, sp, #56
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	bx	lr
.L6:
	.align	2
.L5:
	.word	274877907
	.size	rgb_to_ycbcr, .-rgb_to_ycbcr
	.align	2
	.global	ycbcr_to_rgb
	.type	ycbcr_to_rgb, %function
ycbcr_to_rgb:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl}
	sub	sp, sp, #20
	str	r0, [sp, #4]
	ldrb	r3, [sp, #4]	@ zero_extendqisi2
	ldrb	r6, [sp, #6]	@ zero_extendqisi2
	sub	r3, r3, #16
	ldrb	r5, [sp, #5]	@ zero_extendqisi2
	sub	r6, r6, #128
	mov	r1, r3, asl #7
	sub	r5, r5, #128
	mov	r2, r6, asl #4
	mov	r0, r6, asl #6
	mov	r4, r6, asl #8
	sub	r1, r1, r3, asl #5
	add	r1, r1, r3
	mov	r7, r5, asl #6
	add	r4, r2, r4
	add	r2, r2, r0
	sub	r7, r7, r5, asl #3
	rsb	r4, r6, r4
	mov	ip, r1, asl #2
	mov	r3, r2, asl #2
	ldr	r8, .L9
	mov	r0, r7, asl #3
	rsb	ip, r1, ip
	add	r2, r2, r3
	mov	r1, r4, asl #2
	mov	r3, r5, asl #10
	rsb	r1, r4, r1
	rsb	r0, r7, r0
	rsb	r2, r6, r2
	sub	r3, r3, r5, asl #4
	mov	ip, ip, asl #2
	rsb	r0, r5, r0
	add	r3, r3, r5
	mov	r2, r2, asl #2
	smull	r5, r4, r8, ip
	smull	r6, r5, r8, r1
	mov	r3, r3, asl #1
	smull	r7, r6, r8, r2
	smull	r9, r7, r8, r0
	smull	r9, sl, r8, r3
	mov	ip, ip, asr #31
	mov	r1, r1, asr #31
	rsb	ip, ip, r4, asr #6
	sub	r1, r1, r5, asr #6
	mov	r2, r2, asr #31
	mov	r0, r0, asr #31
	sub	r0, r0, r7, asr #6
	rsb	r2, r2, r6, asr #6
	add	r1, r1, ip
	mov	r3, r3, asr #31
	add	r1, r1, r0
	rsb	r3, r3, sl, asr #6
	add	r2, r2, ip
	add	r3, r3, ip
	bic	r1, r1, r1, asr #31
	bic	r2, r2, r2, asr #31
	strb	r2, [sp, #13]
	strb	r1, [sp, #14]
	bic	r3, r3, r3, asr #31
	strb	r3, [sp, #15]
	ldrb	r0, [sp, #13]	@ zero_extendqisi2
	ldrb	r3, [sp, #14]	@ zero_extendqisi2
	ldrb	r2, [sp, #15]	@ zero_extendqisi2
	orr	r0, r0, r3, asl #8
	orr	r0, r0, r2, asl #16
	add	sp, sp, #20
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl}
	bx	lr
.L10:
	.align	2
.L9:
	.word	274877907
	.size	ycbcr_to_rgb, .-ycbcr_to_rgb
	.align	2
	.global	clamp
	.type	clamp, %function
clamp:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	movs	r3, r0, asr #8
	mvnne	r3, r3
	movne	r0, r3, lsr #24
	bx	lr
	.size	clamp, .-clamp
	.align	2
	.global	rgb_to_ycbcr2
	.type	rgb_to_ycbcr2, %function
rgb_to_ycbcr2:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 376
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	ldr	r3, [r1, #8]
	ldrb	r7, [r3, #0]	@ zero_extendqisi2
	sub	sp, sp, #376
	str	r7, [sp, #368]
	ldr	r2, [r1, #4]
	ldrb	r8, [r2, #0]	@ zero_extendqisi2
	ldrb	r6, [r3, #1]	@ zero_extendqisi2
	str	r8, [sp, #360]
	ldrb	r3, [r3, #2]	@ zero_extendqisi2
	ldrb	r5, [r2, #1]	@ zero_extendqisi2
	ldr	ip, [r1, #0]
	str	r3, [sp, #372]
	ldrb	r9, [ip, #1]	@ zero_extendqisi2
	str	r9, [sp, #352]
	ldrb	fp, [ip, #2]	@ zero_extendqisi2
	str	fp, [sp, #344]
	mov	r8, r6, asl #3
	ldrb	r2, [r2, #2]	@ zero_extendqisi2
	add	r8, r8, r6
	str	r8, [sp, #308]
	str	r2, [sp, #364]
	ldrb	ip, [ip, #0]	@ zero_extendqisi2
	ldr	r7, [r1, #12]
	ldr	sl, [sp, #368]
	str	ip, [sp, #356]
	mov	r3, sl, asl #4
	ldrb	ip, [r7, #0]	@ zero_extendqisi2
	mov	r4, sl, asl #2
	mov	r1, r6, asl #6
	add	r4, r4, r3
	ldr	r3, [sp, #360]
	str	ip, [sp, #340]
	sub	r1, r1, r6, asl #4
	rsb	r1, r1, r6
	mov	sl, r3, asl #2
	mov	r3, r3, asl #4
	ldrb	r2, [r7, #1]	@ zero_extendqisi2
	add	sl, sl, r3
	str	r1, [sp, #8]
	ldr	r3, [sp, #308]
	ldr	r1, [sp, #372]
	mov	r8, r5, asl #3
	ldr	fp, [sp, #368]
	add	r8, r8, r5
	mov	r1, r1, asl #6
	mov	r3, r3, asl #5
	str	r8, [sp, #336]
	str	r1, [sp, #300]
	str	r3, [sp, #12]
	ldr	r8, [sp, #372]
	ldr	r1, [sp, #352]
	ldr	r3, [sp, #360]
	mov	ip, fp, asl #9
	rsb	r4, fp, r4
	sub	ip, ip, fp, asl #6
	mov	r3, r3, asl #9
	mov	fp, r8, asl #9
	mov	r8, r1, asl #3
	mov	r1, r1, asl #6
	str	r3, [sp, #240]
	str	r1, [sp, #212]
	ldr	r3, [sp, #308]
	ldr	r1, [sp, #12]
	add	r3, r3, r1
	str	r3, [sp, #304]
	ldr	r3, [sp, #352]
	ldrb	r7, [r7, #2]	@ zero_extendqisi2
	ldr	r1, [sp, #300]
	add	r8, r8, r3
	str	r7, [sp, #348]
	str	r8, [sp, #288]
	ldr	r7, [sp, #360]
	ldr	r8, [sp, #368]
	ldr	r3, [sp, #240]
	rsb	fp, r1, fp
	str	fp, [sp, #296]
	sub	r3, r3, r7, asl #6
	ldr	fp, [sp, #352]
	add	ip, ip, r8
	ldr	r1, [sp, #364]
	rsb	sl, r7, sl
	sub	r4, r8, r4, asl #3
	ldr	r7, [sp, #8]
	ldr	r8, [sp, #212]
	mov	r7, r7, asl #3
	sub	r8, r8, fp, asl #4
	mov	r1, r1, asl #6
	str	r3, [sp, #236]
	str	r7, [sp, #8]
	str	r8, [sp, #208]
	str	r1, [sp, #324]
	ldr	r3, [sp, #344]
	ldr	r7, [sp, #336]
	ldr	r8, [sp, #364]
	ldr	fp, [sp, #344]
	ldr	r1, [sp, #356]
	mov	r3, r3, asl #6
	mov	r7, r7, asl #5
	mov	r8, r8, asl #9
	mov	fp, fp, asl #9
	mov	r1, r1, asl #2
	str	r3, [sp, #280]
	str	r7, [sp, #332]
	str	r8, [sp, #320]
	str	fp, [sp, #276]
	str	r1, [sp, #260]
	ldr	r3, [sp, #356]
	ldr	r7, [sp, #372]
	mov	fp, r3, asl #4
	ldr	r3, [sp, #340]
	mov	r1, r2, asl #3
	str	r1, [sp, #148]
	mov	r7, r7, asl #3
	mov	r1, r3, asl #4
	str	r7, [sp, #220]
	str	r1, [sp, #12]
	mov	r7, r3, asl #2
	add	r1, sp, #332
	ldmia	r1, {r1, r3}	@ phole ldm
	add	r3, r3, r1
	str	r3, [sp, #328]
	ldr	r3, [sp, #304]
	ldr	r1, [sp, #260]
	rsb	r4, r3, r4
	ldr	r3, [sp, #8]
	add	fp, r1, fp
	str	fp, [sp, #256]
	add	r1, r3, ip
	ldr	fp, [sp, #220]
	ldr	ip, [sp, #300]
	add	fp, fp, ip
	str	fp, [sp, #216]
	ldr	fp, [sp, #148]
	ldr	r3, [sp, #12]
	add	fp, fp, r2
	str	fp, [sp, #144]
	add	r7, r7, r3
	add	r3, sp, #320
	ldmia	r3, {r3, fp}	@ phole ldm
	ldr	ip, [sp, #360]
	rsb	r3, fp, r3
	str	r3, [sp, #316]
	sub	sl, ip, sl, asl #3
	ldr	r3, [sp, #372]
	ldr	ip, [sp, #296]
	add	ip, ip, r3
	str	ip, [sp, #292]
	add	fp, sp, #276
	ldmia	fp, {fp, ip}	@ phole ldm
	rsb	fp, ip, fp
	str	fp, [sp, #272]
	ldr	r3, [sp, #236]
	ldr	fp, [sp, #360]
	add	r3, r3, fp
	str	r3, [sp, #232]
	ldr	ip, [sp, #352]
	ldr	r3, [sp, #208]
	rsb	ip, r3, ip
	str	ip, [sp, #204]
	ldr	fp, [sp, #344]
	ldr	ip, [sp, #288]
	ldr	r3, [sp, #364]
	mov	fp, fp, asl #4
	str	fp, [sp, #12]
	mov	r3, r3, asl #3
	mov	fp, ip, asl #5
	ldr	ip, [sp, #344]
	str	r3, [sp, #228]
	ldr	r3, [sp, #356]
	mov	ip, ip, asl #3
	str	ip, [sp, #196]
	mov	r3, r3, asl #9
	ldr	ip, [sp, #340]
	str	r3, [sp, #184]
	ldr	r3, [sp, #344]
	mov	ip, ip, asl #9
	str	ip, [sp, #168]
	mov	ip, r3, asl #2
	ldr	r3, [sp, #12]
	add	ip, ip, r3
	ldr	r3, [sp, #328]
	rsb	sl, r3, sl
	ldr	r3, [sp, #292]
	add	r4, r4, r3
	ldr	r3, [sp, #288]
	mov	r9, r5, asl #6
	add	fp, r3, fp
	sub	r9, r9, r5, asl #4
	str	fp, [sp, #284]
	rsb	r9, r9, r5
	ldr	fp, [sp, #232]
	mov	r9, r9, asl #3
	ldr	r3, [sp, #228]
	add	r9, r9, fp
	ldr	fp, [sp, #324]
	add	r3, r3, fp
	str	r3, [sp, #224]
	ldr	r3, [sp, #216]
	rsb	r1, r3, r1
	str	r1, [sp, #8]
	ldr	fp, [sp, #196]
	ldr	r1, [sp, #280]
	add	fp, fp, r1
	str	fp, [sp, #192]
	ldr	r3, [sp, #316]
	ldr	fp, [sp, #364]
	add	r3, r3, fp
	str	r3, [sp, #312]
	ldr	r1, [sp, #272]
	ldr	r3, [sp, #344]
	add	r1, r1, r3
	str	r1, [sp, #268]
	ldr	fp, [sp, #256]
	ldr	r1, [sp, #356]
	rsb	fp, r1, fp
	str	fp, [sp, #252]
	ldr	r3, [sp, #204]
	ldr	fp, [sp, #184]
	mov	r3, r3, asl #3
	str	r3, [sp, #200]
	sub	fp, fp, r1, asl #6
	ldr	r3, [sp, #340]
	ldr	r1, [sp, #168]
	sub	r1, r1, r3, asl #6
	str	fp, [sp, #180]
	str	r1, [sp, #164]
	ldr	fp, [sp, #348]
	ldr	r1, [sp, #372]
	mov	fp, fp, asl #4
	mov	r1, r1, asl #4
	str	fp, [sp, #96]
	str	r1, [sp, #64]
	ldr	fp, [sp, #348]
	ldr	r1, [sp, #144]
	rsb	r7, r3, r7
	ldr	r3, [sp, #364]
	mov	fp, fp, asl #6
	mov	r3, r3, asl #4
	mov	r1, r1, asl #5
	str	r3, [sp, #40]
	str	fp, [sp, #152]
	str	r1, [sp, #140]
	ldr	r3, [sp, #348]
	ldr	fp, [sp, #340]
	ldr	r1, [sp, #340]
	mov	r3, r3, asl #9
	mov	fp, fp, asl #3
	mov	r1, r1, asl #8
	str	r3, [sp, #132]
	str	fp, [sp, #116]
	str	r1, [sp, #112]
	ldr	r3, [sp, #348]
	ldr	fp, [sp, #368]
	ldr	r1, [sp, #368]
	mov	r3, r3, asl #2
	mov	fp, fp, asl #3
	mov	r1, r1, asl #8
	str	r3, [sp, #100]
	str	fp, [sp, #84]
	str	r1, [sp, #80]
	ldr	r3, [sp, #372]
	ldr	fp, [sp, #360]
	ldr	r1, [sp, #360]
	mov	r3, r3, asl #2
	mov	fp, fp, asl #3
	mov	r1, r1, asl #8
	str	r3, [sp, #68]
	str	fp, [sp, #52]
	str	r1, [sp, #12]
	ldr	r3, [sp, #364]
	ldr	r1, [sp, #100]
	mov	fp, r3, asl #2
	ldr	r3, [sp, #96]
	add	r1, r1, r3
	str	r1, [sp, #92]
	ldr	r3, [sp, #64]
	ldr	r1, [sp, #68]
	add	r1, r1, r3
	str	r1, [sp, #60]
	ldr	r1, [sp, #40]
	add	fp, fp, r1
	str	fp, [sp, #36]
	ldr	r1, [sp, #284]
	ldr	fp, [sp, #268]
	ldr	r3, [sp, #312]
	rsb	fp, r1, fp
	str	fp, [sp, #264]
	ldr	r1, [sp, #192]
	ldr	fp, [sp, #200]
	add	sl, sl, r3
	ldr	r3, [sp, #224]
	rsb	fp, r1, fp
	rsb	r9, r3, r9
	str	fp, [sp, #188]
	ldr	r3, [sp, #144]
	ldr	fp, [sp, #140]
	add	r3, r3, fp
	str	r3, [sp, #136]
	ldr	r1, [sp, #132]
	ldr	r3, [sp, #152]
	rsb	r1, r3, r1
	str	r1, [sp, #128]
	add	r1, sp, #112
	ldmia	r1, {r1, fp}	@ phole ldm
	add	fp, fp, r1
	str	fp, [sp, #108]
	ldr	r3, [sp, #84]
	ldr	fp, [sp, #80]
	add	r3, r3, fp
	str	r3, [sp, #76]
	ldr	r1, [sp, #52]
	ldr	r3, [sp, #12]
	add	r1, r1, r3
	str	r1, [sp, #48]
	ldr	fp, [sp, #356]
	ldr	r1, [sp, #252]
	sub	fp, fp, r1, asl #3
	str	fp, [sp, #248]
	ldr	r3, [sp, #8]
	ldr	fp, [sp, #180]
	mov	r1, r3, asr #10
	ldr	r3, [sp, #356]
	add	fp, fp, r3
	str	fp, [sp, #176]
	ldr	r3, [sp, #340]
	ldr	fp, [sp, #164]
	sub	r7, r3, r7, asl #3
	add	fp, fp, r3
	mov	r3, r6, asl #9
	str	r3, [sp, #88]
	ldr	r3, [sp, #352]
	str	fp, [sp, #160]
	mov	fp, r2, asl #9
	str	fp, [sp, #120]
	mov	r3, r3, asl #9
	mov	fp, r5, asl #9
	str	fp, [sp, #56]
	str	r3, [sp, #20]
	ldr	fp, [sp, #348]
	mov	r3, ip, asl #2
	str	r3, [sp, #28]
	ldr	r3, [sp, #356]
	mov	fp, fp, asl #3
	str	fp, [sp, #156]
	mov	r3, r3, asl #3
	ldr	fp, [sp, #352]
	str	r3, [sp, #12]
	ldr	r3, [sp, #356]
	mov	fp, fp, asl #2
	mov	r4, r4, asr #10
	str	fp, [sp, #24]
	add	r4, r4, sl, asr #10
	mov	fp, r3, asl #8
	ldr	sl, [sp, #264]
	ldr	r3, [sp, #248]
	add	sl, sl, r3
	str	sl, [sp, #244]
	add	r1, r1, r9, asr #10
	ldr	sl, [sp, #176]
	ldr	r9, [sp, #188]
	mov	r8, r2, asl #6
	add	r9, r9, sl
	sub	r8, r8, r2, asl #4
	ldr	r3, [sp, #160]
	str	r9, [sp, #172]
	rsb	r8, r8, r2
	ldr	r9, [sp, #136]
	mov	r8, r8, asl #3
	add	r8, r8, r3
	rsb	r7, r9, r7
	ldr	r3, [sp, #108]
	ldr	r9, [sp, #340]
	rsb	r3, r9, r3
	ldr	sl, [sp, #120]
	ldr	r9, [sp, #368]
	str	r3, [sp, #104]
	ldr	r3, [sp, #76]
	mov	r2, r2, asl #2
	rsb	r3, r9, r3
	add	r2, r2, sl
	ldr	sl, [sp, #88]
	mov	r6, r6, asl #2
	str	r3, [sp, #72]
	ldr	r9, [sp, #360]
	ldr	r3, [sp, #48]
	add	r6, r6, sl
	ldr	sl, [sp, #56]
	rsb	r3, r9, r3
	mov	r5, r5, asl #2
	str	r3, [sp, #44]
	ldr	r9, [sp, #20]
	ldr	r3, [sp, #24]
	add	r5, r5, sl
	ldr	sl, [sp, #28]
	add	r3, r3, r9
	add	ip, ip, sl
	ldr	sl, [sp, #12]
	str	r3, [sp, #16]
	ldr	r9, [sp, #152]
	ldr	r3, [sp, #156]
	add	fp, sl, fp
	str	fp, [sp, #12]
	ldr	sl, [sp, #128]
	add	fp, r3, r9
	ldr	r3, [sp, #348]
	ldr	r9, [sp, #92]
	add	sl, sl, r3
	ldr	r3, [sp, #60]
	str	sl, [sp, #124]
	mov	sl, r9, asl #2
	mov	r9, r3, asl #2
	ldr	r3, [sp, #36]
	mov	r3, r3, asl #2
	str	r3, [sp, #32]
	ldr	r3, [sp, #244]
	add	r4, r4, r3, asr #10
	ldr	r3, [sp, #172]
	add	r1, r1, r3, asr #10
	ldr	r3, [sp, #104]
	rsb	r8, fp, r8
	ldr	fp, [sp, #124]
	add	r2, r2, r3
	add	r7, r7, fp
	ldr	r3, [sp, #60]
	ldr	fp, [sp, #92]
	str	r2, [sp, #4]
	ldr	r2, [sp, #72]
	add	sl, fp, sl
	add	r9, r3, r9
	ldr	fp, [sp, #44]
	ldr	r3, [sp, #32]
	add	r6, r6, r2
	ldr	r2, [sp, #36]
	add	r5, r5, fp
	add	fp, r2, r3
	ldr	r2, [sp, #16]
	ldr	r3, [sp, #12]
	add	ip, ip, r2
	ldr	r2, [sp, #356]
	rsb	r3, r2, r3
	str	r3, [sp, #12]
	add	r4, r4, r7, asr #10
	ldr	r3, [sp, #4]
	ldr	r7, [sp, #12]
	add	r1, r1, r8, asr #10
	add	r2, r3, sl
	add	r6, r6, r9
	add	r5, r5, fp
	add	ip, ip, r7
	add	r1, r1, #512
	add	r4, r4, #512
	mov	r2, r2, asr #10
	mov	r6, r6, asr #10
	mov	r5, r5, asr #10
	mov	ip, ip, asr #10
	mov	r1, r1, asr #2
	mov	r4, r4, asr #2
	add	r2, r2, #16
	add	r6, r6, #16
	add	r5, r5, #16
	add	ip, ip, #16
	strb	ip, [r0, #0]
	strb	r1, [r0, #5]
	strb	r4, [r0, #4]
	strb	r2, [r0, #3]
	strb	r6, [r0, #2]
	strb	r5, [r0, #1]
	add	sp, sp, #376
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	bx	lr
	.size	rgb_to_ycbcr2, .-rgb_to_ycbcr2
	.align	2
	.global	ycbcr_to_rgb2
	.type	ycbcr_to_rgb2, %function
ycbcr_to_rgb2:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	ldrb	r3, [r0, #2]	@ zero_extendqisi2
	sub	sp, sp, #24
	ldrb	ip, [r0, #0]	@ zero_extendqisi2
	ldrb	fp, [r0, #1]	@ zero_extendqisi2
	ldrb	r4, [r0, #5]	@ zero_extendqisi2
	str	r3, [sp, #8]
	mov	r2, ip, asl #4
	ldrb	r6, [r0, #3]	@ zero_extendqisi2
	sub	r2, r2, ip, asl #2
	str	r6, [sp, #4]
	mov	r3, r2, asl #5
	ldr	r7, [sp, #8]
	add	r2, r2, r3
	ldr	r3, [sp, #4]
	add	r2, r2, ip
	ldr	ip, [sp, #8]
	sub	r4, r4, #128
	mov	r5, fp, asl #4
	mov	r6, r7, asl #4
	mov	r7, r3, asl #4
	sub	r5, r5, fp, asl #2
	sub	r6, r6, ip, asl #2
	sub	r7, r7, r3, asl #2
	mov	ip, r4, asl #6
	mov	r3, r4, asl #4
	str	r3, [sp, #0]
	rsb	ip, r3, ip
	mov	r3, r5, asl #5
	str	r4, [sp, #16]
	add	r5, r5, r3
	mov	r4, r2, asl #2
	mov	r3, ip, asl #4
	mov	r8, r6, asl #5
	rsb	r4, r2, r4
	add	ip, ip, r3
	ldr	r2, [sp, #8]
	ldr	r3, [sp, #16]
	add	r6, r6, r8
	add	r6, r6, r2
	mov	r9, r7, asl #5
	ldr	r2, [sp, #4]
	add	ip, ip, r3
	ldrb	sl, [r0, #4]	@ zero_extendqisi2
	add	r7, r7, r9
	mov	r0, r6, asl #2
	mov	ip, ip, asr #9
	str	ip, [sp, #20]
	add	r5, r5, fp
	ldr	ip, [sp, #16]
	add	r7, r7, r2
	rsb	r0, r6, r0
	ldr	r6, [sp, #0]
	sub	sl, sl, #128
	mov	r2, r5, asl #2
	mov	r8, r7, asl #2
	sub	r4, r4, #18944
	mov	r3, sl, asl #6
	sub	r4, r4, #112
	mov	r9, sl, asl #4
	rsb	r2, r5, r2
	rsb	r8, r7, r8
	sub	r5, r6, ip, asl #2
	ldr	r6, [sp, #20]
	mov	r7, r4, asr #10
	add	r9, r9, r3
	mov	r4, sl, asl #3
	mov	r3, sl, asl #10
	sub	r8, r8, #18944
	add	fp, r6, r7
	add	r4, r4, r3
	sub	r8, r8, #112
	mov	r3, r9, asl #2
	add	ip, r5, ip
	add	r9, r9, r3
	mov	r8, r8, asr #10
	movs	r3, fp, asr #8
	str	r8, [sp, #12]
	mvnne	r3, r3
	mov	r8, ip, asr #4
	movne	fp, r3, lsr #24
	mov	r9, r9, asr #10
	rsb	r3, r8, r7
	add	r4, r4, sl
	rsb	sl, r9, r3
	movs	r3, sl, asr #8
	mov	r4, r4, asr #9
	mvnne	r3, r3
	sub	r2, r2, #18944
	movne	sl, r3, lsr #24
	sub	r2, r2, #112
	add	r3, r4, r7
	ldr	r7, [sp, #20]
	mov	r5, r2, asr #10
	movs	r2, r3, asr #8
	mov	r6, r1
	mvnne	r3, r2
	add	r1, r7, r5
	movne	r3, r3, lsr #24
	movs	r2, r1, asr #8
	strb	r3, [r6, #2]
	mvnne	r3, r2
	movne	r1, r3, lsr #24
	rsb	r3, r8, r5
	strb	sl, [r6, #1]
	rsb	sl, r9, r3
	strb	fp, [r6, #0]
	movs	r3, sl, asr #8
	sub	r0, r0, #18944
	ldr	ip, [sp, #20]
	add	r2, r4, r5
	mvnne	r3, r3
	sub	r0, r0, #112
	mov	r0, r0, asr #10
	movne	sl, r3, lsr #24
	movs	r3, r2, asr #8
	add	r5, ip, r0
	mvnne	r3, r3
	movne	r2, r3, lsr #24
	movs	r3, r5, asr #8
	mvnne	r3, r3
	movne	r5, r3, lsr #24
	add	fp, r6, #3
	rsb	r3, r8, r0
	strb	r2, [fp, #2]
	rsb	r2, r9, r3
	movs	r3, r2, asr #8
	add	r0, r4, r0
	mvnne	r3, r3
	movne	r2, r3, lsr #24
	movs	r3, r0, asr #8
	strb	r1, [r6, #3]
	strb	sl, [fp, #1]
	mvnne	r3, r3
	movne	r0, r3, lsr #24
	ldr	r7, [sp, #12]
	ldr	r3, [sp, #20]
	add	r1, r6, #6
	add	ip, r3, r7
	strb	r0, [r1, #2]
	strb	r5, [r6, #6]
	strb	r2, [r1, #1]
	ldr	r2, [sp, #12]
	movs	r3, ip, asr #8
	mvnne	r3, r3
	movne	ip, r3, lsr #24
	rsb	r3, r8, r2
	rsb	r9, r9, r3
	movs	r3, r9, asr #8
	ldr	r7, [sp, #12]
	mvnne	r3, r3
	movne	r9, r3, lsr #24
	add	r3, r4, r7
	movs	r2, r3, asr #8
	mvnne	r3, r2
	add	r1, r6, #9
	movne	r3, r3, lsr #24
	strb	r3, [r1, #2]
	strb	ip, [r6, #9]
	strb	r9, [r1, #1]
	mov	r0, r6
	add	sp, sp, #24
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp}
	bx	lr
	.size	ycbcr_to_rgb2, .-ycbcr_to_rgb2
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
