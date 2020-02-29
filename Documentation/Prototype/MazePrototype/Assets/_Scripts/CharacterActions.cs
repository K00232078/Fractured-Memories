using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterActions
{
    public CharacterActions()
    {

    }

    public bool Attack(ref CharacterStats attacker, ref CharacterStats defender)
    {
        bool hit = false;
        int attackRoll = 0;
        int attackDamage = 0;

        //roll d20
        int d20 = Random.Range(1, 20);

        //add damage bonus
        attackRoll = d20 + attacker.AttackStrength + 2;

        //if result is greater than enemy ArmorClass
        if(attackRoll>defender.ArmorClass)
        {
            //roll d10 * 2
            int d10 = Random.Range(1, 10);
            attackDamage = d10 * attacker.AttackStrength;
            //apply damage
            defender.DamageHealth(attackDamage);
            hit = true;
        }
        return hit;
    }
}
