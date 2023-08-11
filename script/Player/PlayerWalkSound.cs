using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

public class PlayerWalkSound : MonoBehaviour
{
    public AudioSource AudioSource;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.D)) 
        {
            if (AudioSource.isPlaying != true)
            {
                AudioSource.Play();
            }
        }
        else
        {
            if (AudioSource.isPlaying == true)
            {
                AudioSource.Stop();
            }
        }
    }
}
