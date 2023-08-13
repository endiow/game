using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemyHp : MonoBehaviour
{
    public Slider ShowEnemyHp;
    public Enemy Enemy;
    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Canvas>().worldCamera = GameObject.Find("Main Camera").GetComponent<Camera>();//给画布赋上主摄像头
    }

    // Update is called once per frame
    void Update()
    {
        ShowEnemyHp.value = 100 - Enemy.EnemyInfo.EnemyHp;//血条减少
    }
}
