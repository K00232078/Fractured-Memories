using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ViewportSize : MonoBehaviour
{
    int spriteBox = 4;
    int cameraSize = 3;
    float timerMax = 10;
    float timerCurr = 10;

    bool sightEnabled = false;
    public GameObject holeSprite;
    public GameObject player;
    public Camera cam;

    private void Update()
    {

        if(sightEnabled)
        {
            if(timerCurr>0)
            {
                timerCurr -= Time.deltaTime;
            }
            else
            {
                sightEnabled = false;
                timerCurr = timerMax;
                decreaseSize();
            }
        }


        if(Input.GetKeyDown(KeyCode.Comma))
        {//smaller
            decreaseSize();
        }
        if (Input.GetKeyDown(KeyCode.Period))
        {//bigger
            increaseSize();
        }


    }

    void increaseSize()
    {
        if (cameraSize < 6)
        {
            spriteBox +=2;
            cameraSize++;
            Vector2 newSize = new Vector2(spriteBox, spriteBox);
            holeSprite.transform.localScale = newSize;
            cam.orthographicSize = cameraSize;
        }
    }

    void decreaseSize()
    {
        if (cameraSize > 3)
        {
            spriteBox -=2;
            cameraSize--;
            Vector2 newSize = new Vector2(spriteBox, spriteBox);
            holeSprite.transform.localScale = newSize;
            cam.orthographicSize = cameraSize;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.CompareTag("PowerUpSight"))
        {
            Destroy(collision.gameObject);
            sightEnabled = true;
            increaseSize();
            
        }
    }
}
