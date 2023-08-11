using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StartButtonUI : MonoBehaviour
{
    public void StartButton()
    {
        Debug.Log("开始游戏");
        SceneManager.LoadScene("MainScene");
    }

    public void ExitButton()
    {
        Debug.Log("退出游戏");
        Application.Quit();
    }

    public void RegameButton()
    {
        Debug.Log("重新游戏");
        SceneManager.LoadScene("MainScene");
    }

    public void BackButton()
    {
        Debug.Log("返回主菜单");
        SceneManager.LoadScene("StartScene");
    }
}
