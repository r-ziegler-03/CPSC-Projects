import random
import csv

# Holds all of the names of the characters; used for the bot to select a character
names = []
# Holds all of the weapon names; used for the bot to select a weapon
wep_names = []
# Holds all of the armour names; used for the bot to select an armour piece
arm_names = []
# Holds the attack options for the bot; used when it is the bots turn to attack
bot_attacks = ["special","basic"]
# Tracks what round number the game is currently on
round_number = 1
# A dictionary representing the users character
user_character = {} 
# A dictionary representing the bots character
bots_character = {}

'''
The 10 weapon options
containing their names , class, and the range of damage that their basic attack can do.
'''
sword = {"name": "excalibur" , "class": "knight" , "basic_range": [5,10]}
axe = {"name": "woodpecker" , "class": "tank" , "basic_range": [4,9]}
staff = {"name": "stick" , "class": "assassin" , "basic_range": [7,11]}
fist = {"name": "brass-knuckles" , "class": "assassin" , "basic_range": [7,11]}
bow = {"name": "bow and arrow" , "class": "knight" , "basic_range": [5,10]}
wand = {"name": "abracadabra" , "class": "healer" , "basic_range": [6,10]}
machete = {"name": "bush wacker" , "class": "tank" , "basic_range": [4,9]}
chainsaw = {"name": "tree chopper" , "class": "tank" , "basic_range": [4,9]}
dagger = {"name": "needle" , "class": "assassin" , "basic_range": [7,11]}
crystal_ball = {"name": "truthseer" , "class": "healer" , "basic_range": [6,10]}

'''
Makes a dictionary with the keys being the name of all of the weapons
The values are the dictionaries of the keys name.
'''
weapons = {
    "excalibur": sword,
    "woodpecker": axe,
    "stick": staff,
    "brass-knuckles": fist,
    "bow and arrow": bow,
    "abracadabra": wand,
    "bush wacker": machete,
    "tree chopper": chainsaw,
    "needle": dagger,
    "truthseer": crystal_ball 
}
for keys in weapons.keys():
    wep_names.append(keys)

'''
The 10 armour options
containing their names, the range of damage that they can block when attacked, and the chance that they will block said attacks.
'''
metal_chest = {"name": "metal chest-piece" , "blocking_range": [5,10] , "blocking_chance": 0.5}
flannel = {"name": "flannel shirt" , "blocking_range": [2,4] , "blocking_chance": 0.8}
diamond = {"name": "diamond armour" , "blocking_range": [7,10] , "blocking_chance": 0.3}
wood = {"name": "wood armour" , "blocking_range": [5,8] , "blocking_chance": 0.6}
samurai = {"name": "samurai armour" , "blocking_range": [5,10] , "blocking_chance": 0.5}
shield = {"name": "shield" , "blocking_range": [5,10] , "blocking_chance": 0.5}
barricade = {"name": "barricade" , "blocking_range": [5,8] , "blocking_chance": 0.6}
metal_legs = {"name": "metal legs" , "blocking_range": [5,10] , "blocking_chance": 0.5}
metal_helmet = {"name": "metal helmet" , "blocking_range": [5,10] , "blocking_chance": 0.5}
gloves = {"name": "gloves" , "blocking_range":[2,4] , "blocking_chance": 0.8}

'''
Makes a dictionary with the keys being the name of all of the armours
The values are the dictionaries of the keys name.
'''
armours ={
    "metal chest-piece": metal_chest,
    "flannel shirt": flannel,
    "diamond armour": diamond,
    "wood armour": wood,
    "samurai armour": samurai,
    "shield": shield,
    "barricade": barricade,
    "metal legs": metal_legs,
    "metal helmet": metal_helmet,
    "gloves": gloves
}
for keys in armours.keys():
    arm_names.append(keys)

'''
Welcomes the player to the game
'''
print("Welcome to The battle ground. You will be battling your opponent to the death!")
print("----------------------")

'''
This function displays all of the player options to the user.
Printing their name and class to the screen
This function also appends the names of each line to the names list, to be later used for the bots character decision.
'''
def display_characters():
    char = open("characters.csv",'r')
    reader = csv.reader(char,delimiter=',')
    header = True
    for line in reader:
        if header:
            header = False
        else:
            print(f"{line[0]} is a {line[1]}.")
            names.append(line[0])
    char.close()

'''
Prompts the user to select a character they want to play as
Continues to ask them until they enter a proper name.
'''
def choose_character():
    choose_character.character_select = input("\nWho would you like to use? ").title()
    while True:
        if choose_character.character_select.isdigit() or choose_character.character_select not in names:
            choose_character.character_select = input("\nWho would you like to use? ").title()
        else:
            break

'''
Creates the characters for the user and the bot
Finds the line in the csv file that starts with the same name the user choose in the previous function.
Then adds keys and values to the user_character dictionary from the information on the line.
'''
def assign_character():
    char = open("characters.csv",'r')
    reader = csv.reader(char,delimiter=',')
    bots_choice = random.choice(names)
    for lines in reader:
        if lines[0] == choose_character.character_select:
            user_character["name"] , user_character["class"] = lines[0] , lines[1]
            user_character["special_attack_min"] , user_character["special_attack_max"] = int(lines[2]) , int(lines[3])
            user_character["health"] , user_character["cool_down"] , user_character["turns_since"] = int(lines[4]) , int(lines[5]) , int(lines[6])
            
        if lines[0] == bots_choice:
            bots_character["name"] , bots_character["class"] = lines[0] , lines[1]
            bots_character["special_attack_min"] , bots_character["special_attack_max"] = int(lines[2]) , int(lines[3])
            bots_character["health"] , bots_character["cool_down"] , bots_character["turns_since"] = int(lines[4]) , int(lines[5]) , int(lines[6])
    char.close()
    print(f"You chose {user_character.get('name')} who is a {user_character.get('class')}.")
    print(f"Your opponent chose {bots_character.get('name')} who is a {bots_character.get('class')}.")

'''
Prompts the user to select a weapon to use.
If they choose a weapon that doesn't pair with the class of the character they selected they will inflict minus one damage for every basic attack they do.
'''
def set_weapon():
    print("\n")
    print("You may now choose a weapon from this list below\n--------------------------")
    for keys, values in weapons.items():
        print(f"{keys} works best with a(n) {values['class']}.")
    select_weapon = input("--> ")
    while True:
        if select_weapon not in weapons:
            select_weapon = input("--> ")
        else:
            break
    user_character['weapon'] = weapons.get(select_weapon)
    bots_character['weapon'] = weapons.get(random.choice(wep_names))
    print(f"You chose {user_character['weapon']['name']} which can be very deadly.")
    print(f"Your opponent picked {bots_character['weapon']['name']} which can pack a punch.")
    if weapons[select_weapon]['class'] != user_character['class']:
        print(f"that was not an ideal weapon for your class")
    if bots_character['weapon']['class'] != bots_character['class']:
        print(f"The bot did not choose an ideal weapon!")

'''
Prompts the user to select an armour piece.
'''
def set_armour():
    print("\n")
    print("You may now choose a piece of armour from this list below\n--------------------------")
    for keys, values in armours.items():
        print(f"{keys} can block between {values['blocking_range'][0]} damage and {values['blocking_range'][1]} damage.")
    armour_select = input("--> ")
    while True:
        if armour_select not in armours:
            armour_select = input("--> ")
        else:
            break
    user_character['armour'] = armours.get(armour_select)
    bots_character['armour'] = armours.get(random.choice(arm_names))
    print(f"You chose {user_character['armour']['name']} which has been found to be quite strong!")
    print(f"Your opponent choose {bots_character['armour']['name']} which is not to be messed with.")

'''
This function carries out the basic attack.
Inflicts the necessary damage onto the person defending for the current round.
Checks to see if they blocked any damage and checks how much they blocked.
'''
def basic_attack(attacker,defender):
    blocked = False
    print("Basic Attack Used.")
    damage = random.randint(attacker['weapon']['basic_range'][0] , attacker['weapon']['basic_range'][0])
    block_chance = random.uniform(0,1)
    possible_damage_blocked = random.randint(defender['armour']['blocking_range'][0] , defender['armour']['blocking_range'][1])
    total_damage = damage
    if block_chance <= defender['armour']['blocking_chance']:
        damage_after_blocked = damage - possible_damage_blocked
        if attacker['class'] != attacker['weapon']['class']:
            damage_after_blocked -= 1
            print("Minus one damage point for non ideal weapon \n")
        if damage_after_blocked < 0:
            damage_after_blocked = 0
        total_damage = damage_after_blocked
        blocked = True
    defender['health'] -= total_damage
    if blocked:
        print(f"{attacker['name']} did {damage} this round, but {defender['name']} blocked {possible_damage_blocked} damage.")
        print(f"{attacker['name']} did {total_damage} damage overall this round.")
    else:
        print(f"{attacker['name']} did {total_damage} damage overall this round.")
    attacker['turns_since'] += 1

'''
This function carries out the current players turn by either doing a special attack or basic attack
The special attack can only be used when the user has waited for their characters special cool_down to end
'''
def player_turn(attacker, defender, attack_special):
    #checks if the user selected to use attack special
    if attack_special:
        print("Special Attack Attempted.")
        blocked = False
        #checks if the user has waited for their special attack cool down to end
        if attacker.get("turns_since") >= attacker.get("cool_down"):
            heal_chance = random.uniform(0,1)
            heal = False
            if heal_chance <= 0.2:
                heal = True
            if heal == False:
                damage = random.randint(attacker.get("special_attack_min") , attacker.get("special_attack_max"))
                block_chance = random.uniform(0,1)
                possible_damage_blocked = random.randint(defender['armour']['blocking_range'][0] , defender['armour']['blocking_range'][1])
                total_damage = damage
                if block_chance <= defender['armour']['blocking_chance']:
                    damage_after_blocked = damage - possible_damage_blocked
                    if damage_after_blocked < 0:
                        damage_after_blocked = 0
                    total_damage = damage_after_blocked
                    blocked = True
                defender['health'] -= total_damage
                print(f"Special Attack used")
                if blocked:
                    print(f"{attacker['name']} did {damage} this round, but {defender['name']} blocked {possible_damage_blocked} damage.")
                    print(f"{attacker['name']} did {total_damage} damage overall this round.")
                else:
                    print(f"{attacker['name']} did {total_damage} damage overall this round.")
                attacker['turns_since'] = 0
                
        else:
            basic_attack(attacker,defender)
    else:
        basic_attack(attacker,defender)
    if user_character['health'] < 0:
        user_character['health'] = 0
    if bots_character['health'] < 0:
        bots_character['health'] = 0
    print(f"{user_character['name']} has {user_character['health']} and {bots_character['name']} has {bots_character['health']}")
    

'''
Calls all of the functions to be used
'''
display_characters()
choose_character()
assign_character()
set_weapon()
set_armour()

'''
A list of messages that will print to the screen once the game has ended
'''
def death_message(name):
    messages = ["Oh no you lost, " + name, "Ouch there is no surviving that blow " + name,
    "Congrats, you lost " + name, "Sorry, you didn't win " + name, "Better luck next time " + name,
    "You died " + name]
    return random.choice(messages)

'''
Checks to see if the player is still alive
Tells the player if they won the game
'''
def still_alive(player):
    if player['health'] <= 0:
        print(death_message(player['name']))
        return False
    else:
        print(f"Woohoo {player['name']} you won!!!!")

'''
Carries out each players turn
calling the player_turn function for each player
Checking to see if they are still alive after each turn
'''
while True:
    print(f"ROUND {round_number} -------------- \n")
    ############################################# player 1 turn
    print(f"It is {user_character['name']}'s turn \n")
    attack_special = False
    attack = input("Do you want to use your Basic or Special attack? ").lower()
    while attack != "basic" and attack != "special":
        attack = input("Do you want to use your Basic or Special attack? ").lower()
    if attack == "special":
        attack_special = True
    player_turn(user_character,bots_character,attack_special)
    if bots_character['health'] <= 0:
        break
    ############################################## player 2 turn
    print(f"It is {bots_character['name']}'s turn \n")
    attack_special = False
    attack = random.choice(bot_attacks)
    if attack == "special":
        attack_special = True
    player_turn(bots_character,user_character,attack_special)
    if user_character['health'] <= 0:
        break
    round_number+=1

still_alive(user_character)
still_alive(bots_character)