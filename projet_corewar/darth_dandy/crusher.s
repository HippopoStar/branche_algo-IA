.name "darth dandy"
.comment "An evil lonely dandy, combing the countryside along with himself"

begin:
	sti r1, %:live, %1
	sti r1, %:live1and3, %1
	sti r1, %:live2and4, %1
	sti r1, %:live5and7, %1
	sti r1, %:live6and8, %1
	sti r1, %:live1, %1
	sti r1, %:live2, %1
	sti r1, %:live3, %1
	sti r1, %:live4, %1
	sti r1, %:live5, %1
	sti r1, %:live6, %1
	sti r1, %:live7, %1
	sti r1, %:live8, %1
	sti r1, %:backpack1, %1
	sti r1, %:backpack2, %1
	sti r1, %:backpack3, %1
	sti r1, %:backpack4, %1
decale:
	add r1, r1, r4 # 01
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
	fork %:traveller2
	fork %:fork2 # Le 1er process se duplique une premiere fois
live1and3:
	live %42
	fork %:wait3 # Le 1er process se duplique une seconde fois
	zjmp %:load1 # Le 1er process va se preparer a l'expedition
fork2:
live2and4:
	live %42
	fork %:wait4 # Le 2e process se duplique
	zjmp %:load2 # Le 2e process va se preparer a l'expedition
wait3:
	zjmp %:load3 # Le 3e process attend le 1er et va se preparer
wait4:
	zjmp %:load4 # Le 4e process attend le 2e et va se preparer

# Traveller 1 & 3
load1:
	ld %190054915, r2
	ld %-64, r3
	and r16, r16, r16
live1:
	live %42
	fork %:adventure3
	zjmp %:adventure1
load2:
	ld %251789311, r2
	ld %-60, r3
	and r16, r16, r16
live2:
	live %42
	fork %:adventure3
	zjmp %:adventure1
load3:
	ld %2559, r2
	add r2, r4, r2
	ld %-56, r3
	and r16, r16, r16
live3:
	live %42
	fork %:adventure3
	zjmp %:adventure1
load4:
	ld %3053453312, r2
	ld %-52, r3
	and r16, r16, r16
live4:
	live %42
	fork %:adventure3
	zjmp %:adventure1

traveller2:
	fork %:fork6 # Le 1er process du 2e voyageur se duplique une premiere fois
live5and7:
	live %42
	fork %:wait7 # Le 1er process du 2e voyageur se duplique une seconde fois
	zjmp %:load5 # Le 1er process du 2e voyageur se preparer a l'expedition
fork6:
live6and8:
	live %42
	fork %:wait8 # Le 2e process du 2e voyageur se duplique
	zjmp %:load6 # Le 2e process du 2e voyageur va se preparer a l'expedition
wait7:
	zjmp %:load7 # Le 3e process du 2e voyageur attend le 1er et va se preparer
wait8:
	zjmp %:load8 # Le 4e process du 2e voyageur attend le 2e et va se preparer

# Traveller 2 & 4
load5:
	ld %190054915, r2
	ld %64, r3
	and r16, r16, r16
live5:
	live %42
	fork %:adventure4
	zjmp %:adventure2
load6:
	ld %251789311, r2
	ld %68, r3
	and r16, r16, r16
live6:
	live %42
	fork %:adventure4
	zjmp %:adventure2
load7:
	ld %2304, r2
	add r2, r4, r2
	ld %72, r3
	and r16, r16, r16
live7:
	live %42
	fork %:adventure4
	zjmp %:adventure2
load8:
	ld %905969664, r2
	ld %76, r3
	and r16, r16, r16
live8:
	live %42
	fork %:adventure4
	zjmp %:adventure2

adventure1:
	zjmp %3 # Wait 25 cycles
	sti r2, r3, r16
backpack1:
	live %42
	zjmp %-74
	zjmp %42 # La pour le decalage de 3 octets

adventure2:
	sti r2, r3, r16
backpack2:
	live %42
	zjmp %54
	zjmp %42 # La pour le decalage de 3 octets

adventure3:
	sti r2, r3, r16
backpack3:
	live %42
	zjmp %-74
	zjmp %42 # La pour le decalage de 3 octets

adventure4:
	sti r2, r3, r16
backpack4:
	live %42
	zjmp %54

