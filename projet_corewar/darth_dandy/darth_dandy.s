.name "darth dandy"
.comment "An evil lonely dandy, combing the countryside along with himself"

begin:
	sti r1, %:live, %1
	sti r1, %:backpack, %1
decale:
	add r4, r1, r1 # 01
	add r4, r4, r4 # 02
	add r4, r4, r4 # 03
	add r4, r4, r4 # 04
	add r4, r4, r4 # 05
	add r4, r4, r4 # 06
	add r4, r4, r4 # 07
	add r4, r4, r4 # 08
	add r4, r4, r4 # 09
	add r4, r4, r4 # 10
	add r4, r4, r4 # 11
	add r4, r4, r4 # 12
	add r4, r4, r4 # 13
	add r4, r4, r4 # 14
	add r4, r4, r4 # 15
	add r4, r4, r4 # 16
live:
	live %42
carry:
	and r16, r16, r16
fork1:
	fork %:fork2 # Le 1er process se duplique une premiere fois
	fork %:wait3 # Le 1er process se duplique une seconde fois
	zjmp %:load1 # Le 1er process va se preparer a l'expedition
fork2:
	fork %:wait4 # Le 2e process se duplique
	zjmp %:load2 # Le 2e process va se preparer a l'expedition
wait3:
	zjmp %:load3 # Le 3e process attend le 1er et va se preparer
wait4:
	zjmp %:load4 # Le 4e process attend le 2e et va se preparer
load1:
	ld %190054915, r2
	ld %384, r3
	and r16, r16, r16
	zjmp %:adventure
load2:
	ld %251789311, r2
	ld %388, r3
	and r16, r16, r16
	zjmp %:adventure
load3:
	ld %2305, r2
	add r2, r4, r16
	ld %392, r3
	and r16, r16, r16
	zjmp %:adventure
load4:
	ld %1979711488, r2
	ld %396, r3
	and r16, r16, r16
	zjmp %:adventure
adventure:
	sti r2, r3, r16
backpack:
	live %42
	zjmp %374

