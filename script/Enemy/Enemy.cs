using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.AI;
//using UnityEngine.Audio;

public class Enemy : MonoBehaviour
{
    public EnemyInfo EnemyInfo;
    public EnemyLogic EnemyLogic;
    public AudioSource AudioSourceW;
    public AudioSource AudioSourceH;
    public AudioSource AudioSourceA;

    // Start is called before the first frame update
    void Start()//敌人的初始化
    {
        EnemyInfo = new EnemyInfo();//信息初始化
        EnemyLogic = new EnemyLogic();//逻辑初始化

        EnemyInfo.EnemyMaxHp = 100;
        EnemyInfo.EnemyHp = 100;
        EnemyInfo.EnemyAttackNumber = 10;
        EnemyInfo.EnemyAttackSpeed = 3f;

        EnemyLogic.EnemyInfo = EnemyInfo;
        EnemyLogic.enemyState = EnemyState.Idle;
        EnemyLogic.EnemyMoveTargetPositions = new Transform[8];
        EnemyLogic.navMeshAgent = this.gameObject.GetComponent<NavMeshAgent>();
        EnemyLogic.EnemyObj = this.gameObject;

        EnemyLogic.AudioSourceW = AudioSourceW;
        EnemyLogic.AudioSourceH = AudioSourceH;
        EnemyLogic.AudioSourceA = AudioSourceA;

        for (int i = 0; i < 8; i++)
        {
            string TargetName = "Pos" + i;
            EnemyLogic.EnemyMoveTargetPositions[i] = GameObject.Find(TargetName).transform;
        }
    }

    // Update is called once per frame
    void Update()//每帧更新
    {
        EnemyLogic.EnemyStateControl();
        if (EnemyInfo.EnemyHp <= 0f)
        {
            EnemyLogic.enemyState = EnemyState.Death;
        }
    }
}
