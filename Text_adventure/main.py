def greet_the_player(type):
    if type == "gay":
        print("Velkommen!\nHvorfor er du så skeiv?!")
    elif type == "hetero":
        print("Velkommen!")
    else:
        print("Velkommen!")
    return


def check_player_sexuality():
    player_sexuality_answer = input("E du homo elle? (y/n): ")
    player_sexuality = "hetero"

    if player_sexuality_answer == "y":
        player_sexuality = "gay"
    elif player_sexuality_answer == "n":
        player_sexuality = "hetero"
    else:
        print("Jeg tar det som en kanskje jeg.")
        player_sexuality = "NAN"

    return player_sexuality

def ulv_damage(wolf_age, wolf_weight):
    return wolf_weight/wolf_age


def print_divider():
    print("-------------------")
    return


DEFAULT_AMOUNT_OF_HEALTH = 100
DEFAULT_HEIGHT_CM = 180

health = DEFAULT_AMOUNT_OF_HEALTH
height = DEFAULT_HEIGHT_CM

player_sexuality = check_player_sexuality()

greet_the_player(player_sexuality)

print_divider()
print("Du er en dverg.")
height = 120
print("Din høyde er", height, "cm.")
print("Liv:", health)
print_divider()

print("Du våkner i en mørk skog.")
print("Foran deg ser du en sti.")
valg1 = input("Gå venstre (v) eller høyre (h)? ")

if valg1 == "v":

    print_divider()
    print("Du går mot venstre.")
    print("Du finner en liten kiste.")

    valg2 = input("Åpne kisten? (ja/nei) ")

    if valg2 == "ja":
        print("Du finner et eple.")
        print("Du spiser eplet.")
        health = health + 20
        print("Liv:", health)

    else:
        print("Du lar kisten være.")

    print_divider()
    print("Du fortsetter videre.")
    print("En ulv hopper frem!")

    valg3 = input("Slåss (s) eller løp (l)? ")

    if valg3 == "s":
        print("Ulven biter deg.")
        health -= ulv_damage(wolf1_age, wolf1_weight)
        print("Liv:", health)

        if health > 0:
            print("Du dreper ulven.")
        else:
            print("Du døde.")
            print("GAME OVER")

    else:
        print("Du løper unna.")
        health = health - 10
        print("Liv:", health)

        if health > 0:
            print("Du klarte å rømme.")
        else:
            print("Du døde.")
            print("GAME OVER")

    if health > 0:

        print_divider()
        print("Du kommer til en elv.")

        valg4 = input("Svømme (s) eller bygge bro (b)? ")

        if valg4 == "s":
            print("Vannet er iskaldt.")
            health = health - 20
            print("Liv:", health)

        else:
            print("Du bygger en enkel bro.")
            print("Du kommer trygt over.")

        if health > 0:

            print_divider()
            print("På den andre siden står en trollmann.")

            valg5 = input("Snakke (n) eller angripe (a)? ")

            if valg5 == "n":
                print("Trollmannen gir deg en magisk drikk.")
                health = health + 30
                print("Liv:", health)

            else:
                print("Trollmannen kaster en ildkule.")
                health = health - 40
                print("Liv:", health)

            if health > 0:

                print_divider()
                print("Du finner slottet.")
                print("En drage vokter inngangen.")

                valg6 = input("Kjemp (k) eller snik (s)? ")

                if valg6 == "k":
                    print("Du kjemper modig.")
                    health = health - 30
                    print("Liv:", health)

                    if health > 0:
                        print("Du beseirer dragen.")
                        print("DU VANT!")

                    else:
                        print("Dragen vant.")
                        print("GAME OVER")

                else:
                    print("Du sniker deg forbi.")
                    print("Du finner skatten.")
                    print("DU VANT!")

else:

    print_divider()
    print("Du går mot høyre.")
    print("Du finner en hule.")

    valg2 = input("Gå inn? (ja/nei) ")

    if valg2 == "ja":

        print("Det er veldig mørkt.")
        print("Du snubler.")
        health = health - 20
        print("Liv:", health)

        if health > 0:

            print("Du finner en fakkel.")
            print("Nå kan du se.")

            print("Et skjelett kommer mot deg.")

            valg3 = input("Slåss (s) eller flykte (f)? ")

            if valg3 == "s":
                print("Du knuser skjelettet.")
                health = health - 20
                print("Liv:", health)

            else:
                print("Du løper.")
                health = health - 10
                print("Liv:", health)

            if health > 0:

                print_divider()
                print("Du finner en skatt.")

                valg4 = input("Ta skatten? (ja/nei) ")

                if valg4 == "ja":
                    print("Du blir rik.")
                    print("DU VANT!")

                else:
                    print("Du går tomhendt hjem.")
                    print("DU OVERLEVDE.")

        else:
            print("GAME OVER")

    else:

        print("Du går rundt hulen.")
        print("Du møter en gammel mann.")

        valg5 = input("Hjelpe ham? (ja/nei) ")

        if valg5 == "ja":
            print("Han gir deg et gullsverd.")
            print("Du blir en helt.")
            print("DU VANT!")

        else:
            print("Han blir sint.")
            print("Han jager deg bort.")
            print("Spillet er slutt.")
