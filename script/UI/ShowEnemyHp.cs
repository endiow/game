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
        GetComponent<Canvas>().worldCamera = GameObject.Find("Main Camera").GetComponent<Camera>();//����������������ͷ
    }

    // Update is called once per frame
    void Update()
    {
        ShowEnemyHp.value = 100 - Enemy.EnemyInfo.EnemyHp;//Ѫ������
    }
}
