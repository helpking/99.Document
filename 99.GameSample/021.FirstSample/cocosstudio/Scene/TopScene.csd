<GameProjectFile>
  <PropertyGroup Type="Scene" Name="TopScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.2.3" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="TopScene" CustomClassName="TopScene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="ProjectNode_1" ActionTag="1611714003" Tag="7" IconVisible="True" LeftMargin="90.0000" RightMargin="870.0000" TopMargin="60.0000" BottomMargin="580.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="90.0000" Y="580.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0938" Y="0.9063" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Parts/Role.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="RoleNode" ActionTag="2137179535" Tag="82" IconVisible="True" LeftMargin="700.0000" RightMargin="259.0000" TopMargin="321.0000" BottomMargin="318.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="1.0000" Y="1.0000" />
            <AnchorPoint />
            <Position X="700.0000" Y="318.0000" />
            <Scale ScaleX="0.2000" ScaleY="0.2000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7292" Y="0.4969" />
            <PreSize X="0.0010" Y="0.0016" />
            <FileData Type="Normal" Path="Parts/DemoPlayer.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="uiLayerNode" ActionTag="1328849840" Tag="89" IconVisible="True" RightMargin="960.0000" TopMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="buttonListNode" ActionTag="-1254322717" Tag="100" IconVisible="True" LeftMargin="850.0000" RightMargin="-850.0000" TopMargin="-550.0000" BottomMargin="550.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="walkBtn" ActionTag="1971825809" CallBackType="Touch" CallBackName="onWalkBtnTouch" Tag="155" IconVisible="False" LeftMargin="-23.0000" RightMargin="-23.0000" TopMargin="-18.0000" BottomMargin="-18.0000" TouchEnable="True" FontSize="14" ButtonText="Walk" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="46.0000" Y="36.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="attackBtn" ActionTag="-1920334847" CallBackType="Touch" CallBackName="onAttackBtnTouch" Tag="156" IconVisible="False" LeftMargin="-50.0000" RightMargin="-50.0000" TopMargin="28.5000" BottomMargin="-71.5000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="124" Scale9Height="37" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="100.0000" Y="43.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position Y="-50.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="GUIRes/Button/ui_button_Attack_2.png" Plist="" />
                    <PressedFileData Type="Normal" Path="GUIRes/Button/ui_button_Attack_1.png" Plist="" />
                    <NormalFileData Type="Normal" Path="GUIRes/Button/ui_button_Attack_0.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="850.0000" Y="550.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="LeftTop" ActionTag="11427371" Tag="199" IconVisible="False" LeftMargin="-15.0000" RightMargin="881.0000" TopMargin="-15.0000" BottomMargin="555.0000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="100.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-15.0000" Y="655.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="-0.0156" Y="1.0234" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="GUIRes/Cn03.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="LeftBottom" ActionTag="605131311" Tag="198" IconVisible="False" LeftMargin="-15.0000" RightMargin="881.0000" TopMargin="555.0000" BottomMargin="-15.0000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="100.0000" />
                <AnchorPoint />
                <Position X="-15.0000" Y="-15.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="-0.0156" Y="-0.0234" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="GUIRes/Cn02.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="RightTop" ActionTag="-1384848611" Tag="200" IconVisible="False" LeftMargin="975.0000" RightMargin="-109.0000" TopMargin="-5.0000" BottomMargin="545.0000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="100.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="975.0000" Y="645.0000" />
                <Scale ScaleX="-1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.0156" Y="1.0078" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="GUIRes/Cn03.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="RightBottom" ActionTag="-790251883" Tag="201" IconVisible="False" LeftMargin="975.0000" RightMargin="-109.0000" TopMargin="555.0000" BottomMargin="-15.0000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="100.0000" />
                <AnchorPoint />
                <Position X="975.0000" Y="-15.0000" />
                <Scale ScaleX="-1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.0156" Y="-0.0234" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="GUIRes/Cn02.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>