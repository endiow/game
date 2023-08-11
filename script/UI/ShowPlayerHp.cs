using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShowPlayerHp : MonoBehaviour
{
    public Player Player;
    public Text Text;
    // Start is called before the first frame update
    void Start()
    {
        Player = GameObject.Find("Player").GetComponent<Player>();
        Text = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        Text.text = Player.PlayerHp.ToString();//实时显示血量
    }
}
