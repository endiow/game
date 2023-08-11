using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyHuntTrigger : MonoBehaviour
{
    public Enemy enemy;
    public void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            enemy.EnemyLogic.enemyState = EnemyState.Hunt;
            enemy.EnemyLogic.PlayerObj = other.gameObject;
        }
    }

    public void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            enemy.EnemyLogic.enemyState = EnemyState.Idle;
            enemy.EnemyLogic.PlayerObj = other.gameObject;
        }
    }

}
