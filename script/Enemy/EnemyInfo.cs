using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class EnemyInfo 
{
    public int EnemyMaxHp;
    public int EnemyHp;
    public int EnemyAttackNumber;
    public float EnemySpeed;
    public float EnemyAttackSpeed;
    public GameObject EnemyObj;
    //void KillEnemy()
    //{
    //    if (EnemyHp <= 0f) 
    //    {
    //        GameObject.Destroy(EnemyObj);
    //    }
    //}

}

