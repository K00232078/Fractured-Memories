using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PowerUpManager : MonoBehaviour
{
    //need character stats
    CharacterData characterData;
    private void Start()
    {
        GameObject user = gameObject;
        characterData = user.GetComponent<CharacterData>();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        
        if (collision.gameObject.CompareTag("AttackPowerUp"))
        {
            Debug.Log("Triggered");
            characterData.cs.AttackStrength *= 10;
            Destroy(collision.gameObject);
        }
        else if (collision.gameObject.CompareTag("DefencePowerUp"))
        {
            characterData.cs.ArmorClass += 5;
            Destroy(collision.gameObject);
        }
    }
}
