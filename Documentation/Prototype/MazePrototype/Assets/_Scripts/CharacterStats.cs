using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterStats
{
    int health = 100;
    int armorClass = 15;
    int attackStrength = 3;

    public CharacterStats()
    {

    }

    public int Health { get => health; set => health = value; }
    public int ArmorClass { get => armorClass; set => armorClass = value; }
    public int AttackStrength { get => attackStrength; set => attackStrength = value; }

    public void DamageHealth(int damage)
    {
        health -= damage;
        if(health <= 0)
        {
            health = 0;
        }
    }
}
