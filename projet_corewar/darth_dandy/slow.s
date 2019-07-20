.name "slow"
.comment "raising an army of useless processes"

begin:
	sti r1, %:fork01, %1
	sti r1, %:fork02, %1
	sti r1, %:fork03, %1
	sti r1, %:fork04, %1
	sti r1, %:fork05, %1
	sti r1, %:fork06, %1
	sti r1, %:fork07, %1
	sti r1, %:fork08, %1
	sti r1, %:fork09, %1
	sti r1, %:fork10, %1
	sti r1, %:fork11, %1
	sti r1, %:fork12, %1
	sti r1, %:fork13, %1
	sti r1, %:fork14, %1
	sti r1, %:fork15, %1
	sti r1, %:fork16, %1
	sti r1, %:fork17, %1
	sti r1, %:fork18, %1
	sti r1, %:fork19, %1
	sti r1, %:fork20, %1
	sti r1, %:fork21, %1
	sti r1, %:fork22, %1
	sti r1, %:fork23, %1
	sti r1, %:fork24, %1
	sti r1, %:fork25, %1
	sti r1, %:fork26, %1
	sti r1, %:fork27, %1
	sti r1, %:fork28, %1
	sti r1, %:fork29, %1
	sti r1, %:fork30, %1
	sti r1, %:fork31, %1
	sti r1, %:fork32, %1
	sti r1, %:fork33, %1
	sti r1, %:fork34, %1
	sti r1, %:fork35, %1
	sti r1, %:fork36, %1
	sti r1, %:fork37, %1
	sti r1, %:fork38, %1
	sti r1, %:fork39, %1
	sti r1, %:fork40, %1
	sti r1, %:fork41, %1
	sti r1, %:fork42, %1
	and r16, r16, r16
fork01:
	live %42
	fork %:fork01
fork02:
	live %42
	fork %:fork02
fork03:
	live %42
	fork %:fork03
fork04:
	live %42
	fork %:fork04
fork05:
	live %42
	fork %:fork05
fork06:
	live %42
	fork %:fork06
fork07:
	live %42
	fork %:fork07
fork08:
	live %42
	fork %:fork08
fork09:
	live %42
	fork %:fork09
fork10:
	live %42
	fork %:fork10
fork11:
	live %42
	fork %:fork11
fork12:
	live %42
	fork %:fork12
fork13:
	live %42
	fork %:fork13
fork14:
	live %42
	fork %:fork14
fork15:
	live %42
	fork %:fork15
fork16:
	live %42
	fork %:fork16
fork17:
	live %42
	fork %:fork17
fork18:
	live %42
	fork %:fork18
fork19:
	live %42
	fork %:fork19
fork20:
	live %42
	fork %:fork20
fork21:
	live %42
	fork %:fork21
fork22:
	live %42
	fork %:fork22
fork23:
	live %42
	fork %:fork23
fork24:
	live %42
	fork %:fork24
fork25:
	live %42
	fork %:fork25
fork26:
	live %42
	fork %:fork26
fork27:
	live %42
	fork %:fork27
fork28:
	live %42
	fork %:fork28
fork29:
	live %42
	fork %:fork29
fork30:
	live %42
	fork %:fork30
fork31:
	live %42
	fork %:fork31
fork32:
	live %42
	fork %:fork32
fork33:
	live %42
	fork %:fork33
fork34:
	live %42
	fork %:fork34
fork35:
	live %42
	fork %:fork35
fork36:
	live %42
	fork %:fork36
fork37:
	live %42
	fork %:fork37
fork38:
	live %42
	fork %:fork38
fork39:
	live %42
	fork %:fork39
fork40:
	live %42
	fork %:fork40
fork41:
	live %42
	fork %:fork41
fork42:
	live %42
	fork %:fork42
end:
	zjmp %:fork01

