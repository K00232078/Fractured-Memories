using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack : MonoBehaviour
{
    //detect using object; enemy or player
    //GameObject target;
    GameObject user;
    GameObject defender;

    CharacterActions actions = new CharacterActions();
    bool targetInRange = false;
    string userName;
    string target;
    void Start()
    {
        user = this.transform.parent.gameObject;

        Debug.Log(user.tag);
        if(user.CompareTag("Enemy"))
        {
            target = "Player";
            userName = "Enemy";
        } else
        {
            userName = "Player";
            target = "Enemy";
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            if(defender!=null)
            {
                Debug.Log(userName + " Attacks!");
                CharacterData userStat = user.GetComponent<CharacterData>();
                if (userStat != null)
                {
                    DealDamage();
                }
            }
        }
    }

    void DealDamage()
    {
        if (user == null)
        {
            Debug.Log("Ah shit here we go again");
        }

        CharacterData userStat = user.GetComponent<CharacterData>();
        CharacterData defenderStat = defender.GetComponent<CharacterData>();
        if(userStat==null)
        {
            Debug.Log("Oh Damn");
        }
        if(defenderStat==null)
        {
            Debug.Log("This is fine");
        }
        Debug.Log("Defender Health Before: " + defenderStat.cs.Health);
        bool hit = actions.Attack(ref userStat.cs, ref defenderStat.cs);
        if(hit)
        {
            Debug.Log("Strike");
            Debug.Log("Defender Health: " + defenderStat.cs.Health);
            if(defenderStat.cs.Health==0)
            {
                Destroy(defender);
            }
        } else
        {
            Debug.Log("Attacker Missed");
        }
        
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.CompareTag(target))
        {
            Debug.Log("Target In Range!");
            targetInRange = true;
            defender = collision.gameObject;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.CompareTag(target))
        {
            Debug.Log("Target Not In Range!");
            targetInRange = false;
            defender = null;
        }
    }
}
