using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour
{
    public int PlayerHp;

    // Start is called before the first frame update
    void Start()//玩家初始化
    {
        PlayerHp = 100;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Escape)) 
        {
            SceneManager.LoadScene("DeathScene");
        }
        Death();
    }

    void Death()//死亡界面
    {
        if (PlayerHp <= 0f)
        {
            Debug.Log("玩家死亡");
            SceneManager.LoadScene("DeathScene");
        }
    }
}
